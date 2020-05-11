package com.company;

import javax.swing.*;
import java.awt.*;

public class Drawing extends JPanel {
    int x1 = 0, x2 = 0,y1 = 0, y2 = 0;
    Color color = Color.BLACK;
    public void paintComponent (Graphics g){
        this.setBackground(Color.WHITE);
        g.setColor(color);
        g.drawLine(x1, y1, x2, y2);
    }
}
