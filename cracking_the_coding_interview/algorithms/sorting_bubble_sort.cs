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
  static void countSwaps(int[] a) {
      int swaps = 0;
      for(int i = 0; i < a.Length; i++) {
          for(int j = i + 1; j < a.Length; j++){
              if(a[i] > a[j]){
                  int temp = a[i];
                  a[i] = a[j];
                  a[j] = temp;
                  swaps++;
              }
          }
      }
      
      Console.WriteLine("Array is sorted in " + swaps + " swaps.");
      Console.WriteLine("First Element: " + a[0]);
      Console.WriteLine("Last Element: " + a[a.Length - 1]);
  }
}