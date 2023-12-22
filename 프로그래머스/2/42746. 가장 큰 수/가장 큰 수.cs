using System;

public class Solution {
    public string solution(int[] numbers) {
        int[] countSet = new int[1001];
        foreach(int n in numbers)
        {
            countSet[n]++;
        }
        
        if (countSet[0] == numbers.Length)
            return "0";
        
        string[] nDict = new string[1001];
        for (int i = 0; i<= 1000; i++)
        {
            nDict[i] = i.ToString();
        }
        Array.Sort(nDict, (x, y) =>
            {
                string a = x + y;
                string b = y + x;
                return b.CompareTo(a);
            });
        
        string answer = "";
        foreach(string it in nDict)
        {
            int i = int.Parse(it);
            while(countSet[i]-- > 0)
            {
                answer += it;
            }
        }
        
        return answer;
    }
}