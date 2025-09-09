import java.net.*;
import java.io.*;

public class BotClient {
    public static void main(String[] args) throws Exception {
        if (args.length != 2) {
            System.out.println("Usage: java BotClient <server-ip> <server-port>");
            return;
        }

        InetAddress serverAddr = InetAddress.getByName(args[0]);
        int serverPort = Integer.parseInt(args[1]);

        DatagramSocket socket = new DatagramSocket();
        System.out.println("Bot connected to " + serverAddr + ":" + serverPort);

        final int[] low = {1};
        final int[] high = {100};
        final int[] guess = {(low[0] + high[0]) / 2};

        Thread receiver = new Thread(() -> {
            byte[] buffer = new byte[1024];
            try {
                while (true) {
                    DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                    socket.receive(packet);
                    String msg = new String(packet.getData(), 0, packet.getLength());
                    System.out.println("Server: " + msg);

                    if (msg.contains("guessed")) {
                        System.out.println("Bot win. Closing connection");
                        String exitMsg = "@quit";
                        byte[] buf = exitMsg.getBytes();
                        DatagramPacket exitPacket = new DatagramPacket(buf, buf.length, serverAddr, serverPort);
                        socket.send(exitPacket);
                        socket.close();
                        break;
                    } else if (msg.equals("Bigger")) {
                        //
                    } else if (msg.equals("Lower")) {
                        // 
                    }
                }
            } catch (IOException e) {
                System.out.println("Bot stopped working");
            }
        });
        receiver.start();

        sendGuess(socket, serverAddr, serverPort, guess[0]);
    }

    private static void sendGuess(DatagramSocket socket, InetAddress addr, int port, int guess) throws IOException {
        String msg = String.valueOf(guess);
        System.out.println("Bot send: " + msg);
        byte[] buf = msg.getBytes();
        DatagramPacket packet = new DatagramPacket(buf, buf.length, addr, port);
        socket.send(packet);
    }
}

