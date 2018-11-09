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
    static void checkMagazine(string[] magazine, string[] note) {
        Dictionary<string, int> countPerWord = new Dictionary<string, int>();
        for(int i = 0; i < magazine.Length; i++){
            string word = magazine[i];
            if(!countPerWord.ContainsKey(word)){
                countPerWord.Add(word, 0);
            }
            
            countPerWord[word]++;   
        }
        
        for(int i = 0; i < note.Length; i++){
            string word = note[i];
            if(!countPerWord.ContainsKey(word) || countPerWord[word] == 0){
                Console.WriteLine("No");
                return;
            }
            
            countPerWord[word]--;
        }
        
        Console.WriteLine("Yes");
    }

    static void Main(string[] args) {
        string[] mn = Console.ReadLine().Split(' ');

        int m = Convert.ToInt32(mn[0]);

        int n = Convert.ToInt32(mn[1]);

        string[] magazine = Console.ReadLine().Split(' ');

        string[] note = Console.ReadLine().Split(' ');

        checkMagazine(magazine, note);
    }
}
