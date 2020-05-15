package com.company;

import javax.swing.*;
import java.awt.*;

public class Str extends JPanel {
    int x = 0, y = 0;
    Color color = Color.BLACK;
    String label = "";
    public void paintComponent (Graphics g){
        this.setBackground(Color.WHITE);
        g.setFont(new Font("TimesRoman", Font.PLAIN, 15));
        g.setColor(color);
        g.drawString(label, x,y);
    }
}