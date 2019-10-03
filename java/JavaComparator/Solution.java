import java.util.*;

class Checker implements Comparator<Player>{

   
    public int compare(Player a, Player b){
        int comparison = 0;
        if (a.score < b.score){
            return 1;
        } else if (a.score > b.score){
            return -1;
        } else {
            if (a.name == null && b.name == null){
                return 0;
            } else if (a.name == null) {
                return -1;
            } else if (b.name == null){
                return 1;
            } else {
                comparison = a.name.compareTo(b.name);
                return comparison;
            }
        }
    }
}
class Player{
    String name;
    int score;
    
    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();
        
        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();
     
        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}
