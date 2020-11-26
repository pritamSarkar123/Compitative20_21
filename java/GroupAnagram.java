//Problem:-https://leetcode.com/problems/group-anagrams/
import java.util.*;
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map=new HashMap<>();
        for(String str:strs){
            char[] c=str.toCharArray();
            Arrays.sort(c);
            String sorted=new String(c);
            if(!map.containsKey(sorted)){
                map.put(sorted,new LinkedList<String>());
            }
            map.get(sorted).add(str);
        }
        return new LinkedList<List<String>>(map.values());
    }
}