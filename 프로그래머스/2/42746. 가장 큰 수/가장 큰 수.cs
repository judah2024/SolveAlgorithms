using System;
using System.Text;

public class Solution {
    public string solution(int[] numbers) {
        int[] countSet = new int[1001];
        foreach(var n in numbers)
        {
            countSet[n]++;
        }
        
        if (countSet[0] == numbers.Length)
            return "0";
        
        string[] nDict = new string[1001];
        
        for (int i = 0; i<= 1000; i++)
        {
            nDict[i] = Convert.ToString(i);
        }
        
        Array.Sort(nDict, (x, y) =>
            {
                string a = x + y;
                string b = y + x;
                return b.CompareTo(a);
            });
        
        string answer = "";
        StringBuilder stringBuilder = new StringBuilder();
        
        foreach(var it in nDict)
        {
            int i = Convert.ToInt32(it);
            while(countSet[i] > 0)
            {
                stringBuilder.Append(it);
                countSet[i]--;
            }
        }
        
        answer = stringBuilder.ToString();
        
        return answer;
    }
}