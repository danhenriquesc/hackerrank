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
  static List<int> compareTriplets(List<int> a, List<int> b) {
    int[] ret = new int[] { 0, 0 };
    for(int i = 0; i < a.Count; i++) {
        if(a[i] > b[i]) {
            ret[0]++;
        }else if(a[i] < b[i]) {
            ret[1]++;
        }
    }

    return ret.ToList();
  }
}