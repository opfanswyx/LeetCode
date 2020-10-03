
// @Title: 罗马数字转整数 (Roman to Integer)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-19 23:13:10
// @Runtime: 54 ms
// @Memory: N/A

class Solution {
    public int romanToInt(String s) {
        if(s==null||s.length()==0){
            return 0;
        }
        final Map<Character, Integer> m = new HashMap<>();
        m.put('I', 1);
        m.put('V', 5);
        m.put('X', 10);
        m.put('L', 50);
        m.put('C', 100);
        m.put('D', 500);
        m.put('M', 1000);
        
        int res = m.get(s.charAt(0));
        for(int i=1, len = s.length(); i<len;i++){
            int pre = m.get(s.charAt(i-1));
            int cur = m.get(s.charAt(i));
            
            res += cur - (cur<=pre?0:pre*2);
        }
        return res;
    }
}
