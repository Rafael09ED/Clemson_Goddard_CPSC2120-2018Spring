import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;

public class cmd {
    public static void main(String[] args) throws Exception {
        List<String> commands = new LinkedList<>();
        for (int i = 1; i <= 5; i++) {
            commands.add(1);
        }
        Arrays.asList(4, 6, 10, 20, 50, 100, 200)
        ProcessBuilder builder = new ProcessBuilder(
                "cmd.exe", "/c", "bash", "cd /mnt/c/Users/starm/Downloads/");
        builder.redirectErrorStream(true);
        Process p = builder.start();
        BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
        String line;
        while (true) {
            line = r.readLine();
            if (line == null) {
                break;
            }
            System.out.println(line);
        }
    }
}
