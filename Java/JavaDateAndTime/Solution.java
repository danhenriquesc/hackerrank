import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'findDay' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER month
     *  2. INTEGER day
     *  3. INTEGER year
     */

    public static String findDay(int month, int day, int year) {
                int yearDividedBy4 = (year % 100)/4;
        int YY = year % 100;

        int yearSum = yearDividedBy4 + YY;

        int yearCode = yearSum % 7;

        int monthCode = 0;

        switch(month){
            case 1:
                monthCode = 0;
                break;
            case 2:
                monthCode = 3;
                break;
            case 3:
                monthCode = 3;
                break;
            case 4:
                monthCode = 6;
                break;
            case 5:
                monthCode = 1;
                break;
            case 6:
                monthCode = 4;
                break;
            case 7:
                monthCode = 6;
                break;
            case 8:
                monthCode = 2;
                break;
            case 9:
                monthCode = 5;
                break;
            case 10:
                monthCode = 0;
                break;
            case 11:
                monthCode = 3;
                break;
            case 12:
                monthCode = 5;
                break;
            default:
                monthCode = 0;
        }

        int leapYearCode = (year % 4 == 0 && (month == 1 || month == 2)) ? 1 : 0;

        int centuryCode = 0;

        // If the year is greater than 2200, then "standardize" the year by subtracting 400 until you get a year that is within 1752 and 2200 in order to determine the century code below 
        if (year > 2200){
            while (year > 2200){
                year -= 400;
            }
        }
        
        if (year > 2200 && year < 2300){
            centuryCode = 2;
        } else if (year > 2100){
            centuryCode = 4;
        } else if (year > 2000) {
            centuryCode = 6;
        } else if (year > 1900) {
            centuryCode = 0;
        } else if (year > 1800) {
            centuryCode = 2;
        // 1752 was the year that calendar transitioned from Julian Calendar to Gregorian Calendar
        } else if (year > 1752) {
            centuryCode = 4;
        // September 1752 was the month that calendar transitioned from Julian Calendar to Gregorian Calendar
        } else if (year == 1752 && month >= 9){
            centuryCode = 4;
        // September 14th, 1752 was the date that calendar transitioned from Julian Calendar to Gregorian Calendar
        } else if (year == 1752 && month == 9 && day >= 14){
            centuryCode = 4;
        } else if (year >= 0){
            centuryCode = (18 - (year / 100)) % 7;
        }

        int result = yearCode + monthCode + centuryCode + day - leapYearCode;

        switch (result % 7){
            case 0:
                return "SUNDAY";
            case 1:
                return "MONDAY";
            case 2:
                return "TUESDAY";
            case 3:
                return "WEDNESDAY";
            case 4:
                return "THURSDAY";
            case 5:
                return "FRIDAY";
            default:
                return "SATURDAY";
        }
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int month = Integer.parseInt(firstMultipleInput[0]);

        int day = Integer.parseInt(firstMultipleInput[1]);

        int year = Integer.parseInt(firstMultipleInput[2]);

        String res = Result.findDay(month, day, year);

        bufferedWriter.write(res);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
