import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class table extends Application {

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Multiplication Table");
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10));
        grid.setVgap(8);
        grid.setHgap(10);
        Label numberLabel = new Label("Enter a number:");
        grid.add(numberLabel, 0, 0);

        TextField numberInput = new TextField();
        grid.add(numberInput, 1, 0);
        Button generateButton = new Button("Generate Table");
        grid.add(generateButton, 0, 1, 2, 1);
        Label resultLabel = new Label();
        grid.add(resultLabel, 0, 2, 2, 1);
        generateButton.setOnAction(e -> {
            String inputText = numberInput.getText();
            try {
                int number = Integer.parseInt(inputText);
                StringBuilder table = new StringBuilder();

                for (int i = 1; i <= 10; i++) {
                    table.append(number).append(" x ").append(i).append(" = ").append(number * i).append("\n");
                }

                resultLabel.setText(table.toString());
            } catch (NumberFormatException ex) {
                resultLabel.setText("Please enter a valid number.");
            }
        });
        Scene scene = new Scene(grid, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}