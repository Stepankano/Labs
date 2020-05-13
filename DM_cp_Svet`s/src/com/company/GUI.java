package com.company;

import com.sun.org.apache.xpath.internal.objects.XBoolean;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.ImageObserver;
import java.text.AttributedCharacterIterator;
import javax.swing.*;

public class GUI extends JFrame {
    private JLabel count = new JLabel("Количество вершин: ");
    private JLabel count_two = new JLabel("(рекомендуется не более 12)");

    private JButton button = new JButton("Начертить и раскрасить");
    private TextField counter = new TextField("", 1);


    public GUI() {
        super("Раскраска графа");
        this.setBounds(100, 100, 400, 100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(2, 2, 2, 2));
        container.add(count);
        container.add(counter);
        container.add(count_two);
        button.addActionListener(new ButtonEventListener());
        container.add(button);
    }

    class ButtonEventListener implements ActionListener {

        JFrame frame = new JFrame("Граф");
        int Ox = 300, Oy = 300;

        public void actionPerformed(ActionEvent e) {
            String str = counter.getText(); //1. Создание и рандомное заполнение матрицы смежности
            int size = 0;
            for (int i = 0; i < str.length(); i++) {
                size = size * 10 + (((int) (str.charAt(i))) - 48);
            }
            boolean[][] matrix = new boolean[size][size];
            for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                    matrix[i][k] = (Math.random() > 0.5f ? true : false);
                }
            }

            for (int k = 0; k < size; k++) {
                matrix[k][k] = false;
                for (int j = 0; j < size; j++) {
                    matrix[k][j] = (matrix[k][j] && matrix[j][k]);
                }
            }

            int[] vertex = new int[size]; //2. Подсчет степеней и дуг(примерно)
            int edge = 0;
            for (int i = 0; i < size; i++) {
                vertex[i] = 0;
                for (int k = 0; k < size; k++) {
                    vertex[i] += (matrix[i][k] == true ? 1 : 0);
                    edge += (matrix[i][k] == true ? 1 : 0);
                }
            }


            int[] stack = new int[size]; //3.Создание стека вершин

            for (int i = 0; i < size; i++) {
                stack[i] = -1;
            }
            int stack_num = 0;

            int[][] array = new int[size][3]; //0 - степень, 1 - номер, 2 - цвет

            for (int i = 0; i < size; i++) {
                array[i][0] = vertex[i];
                array[i][1] = i;
                array[i][2] = -1;
            }

            //Сортировка (в начале - самые большие)
            for (int i = 0; i < size - 1; i++) {

                if (array[i][0] < array[i + 1][0]) {

                    int tmp = array[i][0];
                    array[i][0] = array[i + 1][0];
                    array[i + 1][0] = tmp;
                    tmp = array[i][1];
                    array[i][1] = array[i + 1][1];
                    array[i + 1][1] = tmp;
                    tmp = array[i][2];
                    array[i][2] = array[i + 1][2];
                    array[i + 1][2] = tmp;
                    i = -1;
                }
            }
            int[][] posis = new int[size][3];
            for (int i = 0; i < size; i++) {
                array[i][2] = 0;
                posis[i][0] = -10000;
                posis[i][1] = -10000;
            }
            array[0][2] = 1;
            int tmp_clr = 2;
            for (int i = 0; i < size - 1; i++) {

                if (array[i][2] == 0) {
                    array[i][2] = tmp_clr;
                    tmp_clr += 1;
                }


                for (int k = i + 1; k < size; k++) {

                    if ((matrix[array[i][1]][array[k][1]] == false) && array[k][2] == 0) {
                        int y = 0;
                        int clr = array[i][2];
                        for (int x = 0; x < k; x++) {
                            if (array[x][2] == clr) {
                                if ((matrix[array[x][1]][array[k][1]] == true)) {
                                    x = k + 1;
                                }
                            }
                            array[k][2] = (x == k + 1) ? 0 : clr;
                        }
                    }
                }
            }


            String sum = "Степень ";
            String sum2 = "\n номер ";
            String sum3 = "\n цвет";
            for (int i = 0; i < size; i++) {
                sum += array[i][0] + " ";
                sum2 += array[i][1] + " ";
                sum3 += array[i][2] + " ";
            }
            JOptionPane.showMessageDialog(null, sum + sum2 + sum3, "Итог", JOptionPane.PLAIN_MESSAGE);

            double angle = (360 / size) * (Math.PI / 180);// 4. Рисование) // добавить цветов)
            int color = 1;
            for (int i = 0;i < size; i++) {
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                Circ dot = new Circ();

                dot.setBackground(Color.WHITE);
                dot.x = (int) (Ox + (200 * Math.sin(array[i][1] * angle)));
                dot.y = (int) (Oy - (200 * Math.cos(array[i][1] * angle)));
                dot.wid = 15;
                dot.hei = 15;
                dot.color = dot.next_col(array[i][2]);
                for (int h = 0; h < size; h++) {
                    if (posis[h][1] == -10000) {
                        posis[h][0] = dot.x;
                        posis[h][1] = dot.y;
                        posis[h][2] = array[i][1];
                        break;
                    }
                }

                frame.add(dot);

                frame.setSize(700, 700);
                frame.setVisible(true);
            }
            for (
                    int k = 0;
                    k < size; k++) {
                for (int j = 0; j < size; j++) {
                    if (matrix[k][j] == true) {

                        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                        Drawing draw = new Drawing();
                        draw.setBackground(Color.WHITE);
                        for (int i = 0; i < size; i++) {
                            if (k == posis[i][2]) {
                                draw.x1 = posis[i][0] + 7;
                                draw.y1 = posis[i][1] + 7;
                            }
                        }
                        for (int i = 0; i < size; i++) {
                            if (j == posis[i][2]) {
                                draw.x2 = posis[i][0] + 7;
                                draw.y2 = posis[i][1] + 7;
                            }
                        }
                        frame.add(draw);
                        frame.setSize(700, 700);
                        frame.setVisible(true);
                    }
                }


            }
            for (int i = 0;i < size; i++) {
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                Str labe = new Str();
                labe.x = (int) (Ox + (220 * Math.sin(array[i][1] * angle)));
                labe.y = (int) (Oy - (220 * Math.cos(array[i][1] * angle))+15);
                labe.label = "" +( array[i][1]+1);
                frame.add(labe);
                frame.setSize(700, 700);
                frame.setVisible(true);
            }
            String sum4 = "Mатрица "+size+" x "+size+"\n\n";

            for (int i = 0; i < size; i++) {

                for (int j = 0; j < size; j++) {
                    sum4 += (matrix[i][j] == true ? 1 : 0) + " ";
                }
                sum4 += "\n";
            }
            JOptionPane.showMessageDialog(null, sum4, "Итог", JOptionPane.PLAIN_MESSAGE);





/*
        public void circ1() {
JFrame frame = new JFrame("Граф");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            double angle = (360 / mult) * (Math.PI / 180);
            for (int i = 0; i < 10000; i++) {
                Drawing draw = new Drawing();
                draw.setBackground(Color.WHITE);
                draw.x1 = kx;
                draw.x2 = (int) (kx + (100 * Math.sin(i * angle)));
                draw.y1 = ky;
                draw.y2 = (int) (ky - (100 * Math.cos(i * angle)));
                frame.add(draw);
                frame.setSize(600, 600);
                frame.setVisible(true);
                kx = draw.x2;
                ky = draw.y2;
                for (int j = 0; j < 100; j++) {
                    if (Math.abs(secmat[j][0] - kx) < mult && Math.abs(secmat[j][1] - ky) < mult) {
                        i = 10000;
                        break;
                    } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                        (secmat)[j][0] = kx;
                        (secmat)[j][1] = ky;
                        break;
                    }
                }
            }

        }
*/
        }

    }
}
