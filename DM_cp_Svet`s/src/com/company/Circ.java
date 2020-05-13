package com.company;

import javax.swing.*;
import java.awt.*;

public class Circ extends JPanel {
    int x = 0, y = 0, wid = 0, hei = 0;
    Color color = Color.BLUE;
    public void paintComponent (Graphics g){
        this.setBackground(Color.WHITE);
        g.setColor(color);
        g.fillOval(x, y, wid, hei);
    }
    public  Color next_col (int color){



        if (color == 1){
            return Color.RED;
        }
        if (color == 2){
            return Color.GREEN;
        }
        if (color == 3){
            return Color.MAGENTA;
        }
        if (color == 4){
            return Color.YELLOW;
        }
        if (color == 5){
            return Color.DARK_GRAY;
        }
        if (color == 6){
            return Color.CYAN;
        }
        if (color == 7){
            return Color.PINK;
        }
        if (color == 8){
            return Color.ORANGE;
        }
        if (color == 9){
            return Color.BLACK;
        }
        if (color == 10){
            return Color.BLUE;
        }
        if (color == 11){
            return Color.LIGHT_GRAY;
        }
        if (color == 12){
            return Color.GRAY;
        }
        return Color.white;


    }
}