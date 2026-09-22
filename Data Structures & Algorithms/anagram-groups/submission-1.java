class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> charCnt = new HashMap<>();
        int id = 0;
        List<List<String>> result = new ArrayList<>();
        for(int i = 0; i < strs.length; i++){
            int[] cnt = new int[26];
            for(int j = 0; j < strs[i].length(); j++){
                cnt[strs[i].charAt(j)-'a']++;
            }
            String key = Arrays.toString(cnt);
            if(charCnt.get(key) == null){
                result.add(new ArrayList<>(List.of(strs[i])));
                charCnt.put(key, id++);
            }
            else{
                int ind = charCnt.get(key);
                result.get(ind).add(strs[i]);
            }
        }
        return result;
    }
}
