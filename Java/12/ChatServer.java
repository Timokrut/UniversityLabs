import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

public class ChatServer {
    private static final int PORT = 12345;
    private static final Map<String, ClientHandler> clients = new ConcurrentHashMap<>();

    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);

            while (true) {
                Socket socket = serverSocket.accept();
                new Thread(new ClientHandler(socket)).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static class ClientHandler implements Runnable {
        private Socket socket;
        private PrintWriter out;
        private String username;

        ClientHandler(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try (BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
                out = new PrintWriter(socket.getOutputStream(), true);

                out.println("Enter your name:");
                username = in.readLine();
                if (username == null || username.isEmpty()) {
                    username = "User" + new Random().nextInt(1000);
                }

                clients.put(username, this);
                broadcast(">> " + username + " connected to chat");

                String msg;
                while ((msg = in.readLine()) != null) {
                    if (msg.startsWith("@senduser ")) {
                        String[] parts = msg.split(" ", 3);
                        if (parts.length >= 3) {
                            String target = parts[1];
                            String privateMsg = parts[2];
                            sendToUser(target, "[PM from " + username + "]: " + privateMsg);
                        } else {
                            out.println("Usage: @senduser <name> <msg>");
                        }
                    } else {
                        broadcast("[" + username + "]: " + msg);
                    }
                }
            } catch (IOException e) {
                System.out.println("User disconnected: " + username);
            } finally {
                clients.remove(username);
                broadcast(">> " + username + " left chat");
                try {
                    socket.close();
                } catch (IOException ignored) {}
            }
        }

        private void broadcast(String msg) {
            for (ClientHandler client : clients.values()) {
                client.out.println(msg);
            }
        }

        private void sendToUser(String user, String msg) {
            ClientHandler client = clients.get(user);
            if (client != null) {
                client.out.println(msg);
            } else {
                out.println("User " + user + " not found");
            }
        }
    }
}
