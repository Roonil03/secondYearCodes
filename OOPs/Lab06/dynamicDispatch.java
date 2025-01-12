class Game {
    void type() {
        System.out.println("Indoor & outdoor games");
    }
}

class Cricket extends Game {
    void type() {
        System.out.println("Cricket is an outdoor game");
    }
}

class Chess extends Game {
    void type() {
        System.out.println("Chess is an indoor game");
    }
}

public class dynamicDispatch {
    public static void main(String[] args) {
        Game game = new Cricket(); 
        game.type(); 

        game = new Chess(); //e
        game.type(); 
    }
}
// public class  {
    
// }
