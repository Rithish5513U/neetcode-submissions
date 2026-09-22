class Pair{
    private int first;
    private int second;

    Pair(int first, int second){
        this.first = first;
        this.second = second;
    }

    public int getFirst() {
        return first;
    }

    public void setFirst(int first) {
        this.first = first;
    }

    public int getSecond() {
        return second;
    }

    public void setSecond(int second) {
        this.second = second;
    }
}

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.getFirst(), a.getFirst())
        );
        Map<Integer, Integer> numCnt = new HashMap<>();
        for(int num : nums){
            numCnt.put(num, numCnt.getOrDefault(num, 0)+1);
        }
        for(Map.Entry<Integer, Integer> entry : numCnt.entrySet()){
            pq.offer(new Pair(entry.getValue(), entry.getKey()));
        }
        int[] result = new int[k];
        for(int i = 0; i < k; i++){
            result[i] = pq.poll().getSecond();
        }
        return result;
    }
}
