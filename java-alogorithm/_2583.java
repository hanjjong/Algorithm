import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class _2583 {
    public static Queue<int[]> queue = new LinkedList<>();
    public static int[][] visited = new int[100][100];
    static int n, m, k;

    public static int dx[] = {1, -1, 0, 0};
    public static int dy[] = {0, 0, 1, -1};

    public static List<Integer> result = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine(), " ");
        m = Integer.parseInt(stringTokenizer.nextToken());
        n = Integer.parseInt(stringTokenizer.nextToken());
        k = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i < k; i++) {
            int a = 0, b = 0, c = 0, d = 0;
            stringTokenizer = new StringTokenizer(br.readLine(), " ");
            a = Integer.parseInt(stringTokenizer.nextToken());
            b = Integer.parseInt(stringTokenizer.nextToken());
            c = Integer.parseInt(stringTokenizer.nextToken());
            d = Integer.parseInt(stringTokenizer.nextToken());
            for (int o = b; o < d; o++) {
                for (int p = a; p < c; p++) {
                    if (visited[o][p] == 0)
                        visited[o][p] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0)
                    result.add(bfs(i , j));
            }
        }
        Collections.sort(result);

        System.out.println(result.size());
        for (int num : result)
            System.out.print(num + " ");
    }

    private static int bfs(int i, int j) {
        queue.add(new int[]{i, j});
        visited[i][j] = 1;
        int res = 1;
        while (!queue.isEmpty()) {
            int cur[] = queue.poll();
            int cx = cur[0];
            int cy = cur[1];

            for (int loop = 0; loop < 4; loop++) {
                int nx = cx + dx[loop];
                int ny = cy + dy[loop];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (visited[nx][ny] == 1) continue;
                visited[nx][ny] = 1;
                queue.add(new int[]{nx, ny});
                res++;
            }
        }
        return res;
    }
}
