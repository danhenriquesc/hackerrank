using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(string a, string b) {
        int[] first = new int[26];
        int[] second = new int[26];
        for(int i = 0; i < a.Length; i++){
            int idx = (int)a[i] - (int)'a';
            first[idx]++;
        }
        
        for(int i = 0; i < b.Length; i++){
            int idx = (int)b[i] - (int)'a';
            second[idx]++;
        }
        
        int delCnt = 0;
        for(int i = 0; i < 26; i++){
            delCnt += Math.Abs(first[i] - second[i]);
        }
        
        return delCnt;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string a = Console.ReadLine();

        string b = Console.ReadLine();

        int res = makeAnagram(a, b);

        textWriter.WriteLine(res);

        textWriter.Flush();
        textWriter.Close();
    }
}
