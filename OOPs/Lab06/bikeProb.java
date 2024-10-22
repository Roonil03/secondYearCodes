public class bikeProb {
    public static void main(String[] args) {
        Bike bike = new Splendar();
        bike.run();
        Bike bike2 = new Bike();
        bike2.run();
        System.out.println("Direct access of speedLimit: " + bike.speedLimit);
    }
}
class Bike {
    int speedLimit = 80;
    void run() {
        System.out.println("Bike speed limit is: " + this.speedLimit);
    }
}

class Splendar extends Bike {
    int speedLimit = 100;
    void run() {
        System.out.println("Splendar speed limit is: " + this.speedLimit /* + " " + super.speedLimit*/);
    }
}
