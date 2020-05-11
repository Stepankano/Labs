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
    public  Color next_col (Color color){
        if (color == Color.BLUE){
            return Color.RED;
        }
        if (color == Color.RED){
            return Color.GREEN;
        }
        if (color == Color.GREEN){
            return Color.MAGENTA;
        }
        if (color == Color.MAGENTA){
            return Color.YELLOW;
        }
        if (color == Color.YELLOW){
            return Color.DARK_GRAY;
        }
        if (color == Color.DARK_GRAY){
            return Color.CYAN;
        }
        if (color == Color.CYAN){
            return Color.PINK;
        }
        if (color == Color.PINK){
            return Color.ORANGE;
        }
        if (color == Color.ORANGE){
            return Color.BLACK;
        }
        return Color.BLACK;
    }
}