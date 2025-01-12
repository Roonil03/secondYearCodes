class MarkOutOfBoundsException extends Exception {
    public MarkOutOfBoundsException(String message) {
        super(message);
    }
}

public class studentV2{
    private String name;
    private int marks;

    public studentV2(String name, int marks) throws MarkOutOfBoundsException {
        this.name = name;
        setMarks(marks);
    }

    public void setMarks(int marks) throws MarkOutOfBoundsException {
        if (marks > 100) {
            throw new MarkOutOfBoundsException("Marks cannot be greater than 100: " + marks);
        }
        this.marks = marks;
    }

    public int getMarks() {
        return marks;
    }

    public String getName() {
        return name;
    }
}

class ExceptionMarksOutOfBounds {
    public static void main(String[] args) {
        try {
            studentV2 student = new studentV2("Alice", 105);
            System.out.println("Student Name: " + student.getName());
            System.out.println("Marks: " + student.getMarks());
        } catch (MarkOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }

        try {
            studentV2 student2 = new studentV2("Bob", 90);
            System.out.println("Student Name: " + student2.getName());
            System.out.println("Marks: " + student2.getMarks());
        } catch (MarkOutOfBoundsException e) {
            System.out.println(e.getMessage());
        }
    }
}
