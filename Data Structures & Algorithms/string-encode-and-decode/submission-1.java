class Solution {

    public String encode(List<String> strs) {
        StringBuilder mutableString = new StringBuilder();
        for(int i = 0; i < strs.size(); i++){
            int len = strs.get(i).length();
            mutableString.append(len);
            mutableString.append("#");
            mutableString.append(strs.get(i));
        }
        return new String(mutableString);
    }

    public List<String> decode(String str) {
        int size = str.length();
        int ind = 0;
        List<String> result = new ArrayList<>();
        while(ind < size){
            int num = 0;
            while(str.charAt(ind) != '#'){
                num = num * 10 + (str.charAt(ind)-'0');
                ind++;
            }
            ind++;
            StringBuilder mutableString = new StringBuilder();
            while(num > 0){
                mutableString.append(str.charAt(ind++));
                num--;
            }
            result.add(new String(mutableString));
        }
        return result;
    }
}
