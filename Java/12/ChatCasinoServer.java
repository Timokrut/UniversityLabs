import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

public class ChatCasinoServer {
    private static final int PORT = 12345;
    private static final Map<String, ClientHandler> clients = new ConcurrentHashMap<>();
    private static final Map<String, Integer> bets = new ConcurrentHashMap<>();
    private static final Random random = new Random();

    public static void main(String[] args) {
        ExecutorService pool = Executors.newCachedThreadPool();

        new Thread(() -> gameLoop()).start();

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Casino Server started on port " + PORT);

            while (true) {
                Socket socket = serverSocket.accept();
                pool.execute(new ClientHandler(socket));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void gameLoop() {
        while (true) {
            try {
                broadcast("===NEW ROUND===\n\nYou now have 10 seconds to bet (@bet [0..36])");
                bets.clear();

                Thread.sleep(10000); 

                int winningNumber = random.nextInt(37); 
                broadcast("\n\n>>> Winning number is " + winningNumber);

                List<String> winners = new ArrayList<>();
                for (var entry : bets.entrySet()) {
                    if (entry.getValue() == winningNumber) {
                        winners.add(entry.getKey());
                    }
                }

                if (winners.isEmpty()) {
                    broadcast(">>> No winners at this round");
                } else {
                    broadcast("Winners: ");
                    for (String winner : winners) {
                        broadcast(winner);
                    }
                }

                Thread.sleep(5000);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private static void broadcast(String msg) {
        for (ClientHandler client : clients.values()) {
            client.out.println(msg);
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
                broadcast(">> " + username + " connected to casino");
                out.println("Use @bet <number> to bet");

                String msg;
                while ((msg = in.readLine()) != null) {
                    if (msg.startsWith("@bet ")) {
                        try {
                            int number = Integer.parseInt(msg.split(" ")[1]);
                            if (number < 0 || number > 36) {
                                out.println("You can bet only on number in range 0..36");
                            } else {
                                bets.put(username, number);
                                out.println("Your bet on " + number + " accepted");
                            }
                        } catch (Exception e) {
                            out.println("Usage: @bet <number>");
                        }
                    } else {
                        out.println("You can bet using command @bet <number>.");
                    }
                }
            } catch (IOException e) {
                System.out.println("User disconnected: " + username);
            } finally {
                clients.remove(username);
                broadcast(">> " + username + " left casino");
                try {
                    socket.close();
                } catch (IOException ignored) {}
            }
        }
    }
}
