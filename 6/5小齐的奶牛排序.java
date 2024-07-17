  public static void main(String[] args) {
        int n = nextInt(), m = nextInt();
        graph = new ArrayList[n + 1];
        List<Integer>[] graphClone = new ArrayList[n + 1];// 如果不满足规则需要回退该组前面已执行的规则, 转换为如果满足一组规则则记录到clone中
        Arrays.setAll(graph, k -> new ArrayList<>());
        Arrays.setAll(graphClone, k -> new ArrayList<>());
        int[] indegree = new int[n + 1];
        int[] indegreeClone = new int[n + 1];
        out:
        for (int i = 0; i < m; i++) {
            int k = nextInt();
            int[] X = new int[k];
            int pre = nextInt();
            for (int j = 0; j < k - 1; j++) {
                int cur = nextInt();
                if (check(pre, cur)) break out;// 检查能否满足pre->cur
                X[j] = pre;
                graph[pre].add(cur);
                indegree[cur]++;
                pre = cur;
            }
            for (int j = 0; j < k; j++) {// 如果整体clone会超时,所以记录操作了哪些点
                graphClone[X[j]] = new ArrayList<>(graph[X[j]]);
            }
            indegreeClone = indegree.clone();
        }
        //按照拓扑序输出
        Queue<Integer> queue = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            if (indegreeClone[i] == 0) {
                queue.offer(i);
            }
        }
        StringBuilder ans = new StringBuilder();
        while (!queue.isEmpty()) {
            int p = queue.poll();
            ans.append(p).append(" ");
            for (int c : graphClone[p]) {
                indegreeClone[c]--;
                if (indegreeClone[c] == 0) {
                    queue.offer(c);
                }
            }
        }
        System.out.println(ans);
    }

    /**
     现在pre需要指向cur,所以检查cur的可达路径中是否包含pre,如果包含则无法满足
     */
    static boolean check(int pre, int cur) {
        if (graph[cur].contains(pre)) return true;
        for (int v : graph[cur]) {
            if (check(pre, v)) return true;
        }
        return false;
    }
