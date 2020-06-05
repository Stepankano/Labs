package com.company;

import com.sun.org.apache.xpath.internal.objects.XBoolean;

import java.awt.*;
import java.awt.event.*;
import java.awt.image.ImageObserver;
import java.text.AttributedCharacterIterator;
import javax.swing.*;

public class GUI extends JFrame {
    private JLabel empt = new JLabel("");
    private JButton button = new JButton("Начертить");

    private TextField forming_1 = new TextField("", 1);
    private TextField defining_left_1 = new TextField("", 1);
    private TextField defining_right_1 = new TextField("", 1);

    private TextField forming_2 = new TextField("", 1);
    private TextField defining_left_2 = new TextField("", 1);
    private TextField defining_right_2 = new TextField("", 1);

    private TextField forming_3 = new TextField("", 1);
    private TextField defining_left_3 = new TextField("", 1);
    private TextField defining_right_3 = new TextField("", 1);

    private TextField forming_4 = new TextField("", 1);
    private TextField defining_left_4 = new TextField("", 1);
    private TextField defining_right_4 = new TextField("", 1);

    private TextField forming_5 = new TextField("", 1);
    private TextField defining_left_5 = new TextField("", 1);
    private TextField defining_right_5 = new TextField("", 1);

    private TextField forming_6 = new TextField("", 1);
    private TextField defining_left_6 = new TextField("", 1);
    private TextField defining_right_6 = new TextField("", 1);


    private JLabel forming_label = new JLabel("Образующие");
    private JLabel forming_label_tip = new JLabel("(по одной образующей)");
    private JLabel forming_defining_left = new JLabel("Определяющие");
    private JLabel forming_defining_right = new JLabel("cоотношения");
    private JLabel forming_defining_left_tip = new JLabel("(левосторонние значения определяющих (a2 это a^2))");
    private JLabel forming_defining_right_tip = new JLabel("(правосторонние значения определяющих)");
    private JLabel forming_defining_right_tip2 = new JLabel("(рекомендуется вводить по убыванию степени)");


    public GUI() {
        super("Задание графа по образующим и определяющим соотношениям");

        JOptionPane.showMessageDialog(null, "Программа строит граф по образующим , которые указываются в первом столбце по одной в поле,\nи определяющим соотношениям вида s^r = e (s - образующая, r - целая степень), при этом левостороннее значение (a^2 записывается как a2) записывается во втором столбце\nа правостороннее (это e) - в третьем( для удобства степень ограничена 9-ю). \nРекомендуется указывать степени в порядке невозрастания\n Пример ввода:\n a   a4   e\n b   b3   e ","Инструкция",JOptionPane.PLAIN_MESSAGE);
        this.setBounds(100, 100, 1000, 150);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container container = this.getContentPane();
        container.setLayout(new GridLayout(5, 3, 2, 2));
        container.add(forming_label);
        container.add(forming_defining_left);
        container.add(forming_defining_right);
        container.add(forming_label_tip);
        container.add(forming_defining_left_tip);
        container.add(forming_defining_right_tip);
        container.add(forming_1);
        container.add(defining_left_1);
        container.add(defining_right_1);
        container.add(forming_2);
        container.add(defining_left_2);
        container.add(defining_right_2);
        container.add(empt);
        container.add(forming_defining_right_tip2);
        button.addActionListener(new ButtonEventListener());
        container.add(button);
    }

    class ButtonEventListener implements ActionListener {
        int ang1 = -1, ang2 = -1, ang3 = -1, ang4 = -1, ang5 = -1, ang6 = -1;
        int mult1 = -1, mult2 = -1, mult3 = -1, mult4 = -1, mult5 = -1, mult6 = -1;
        int sec_count = 10000;
        int kx = 200, ky = 300;
        int[][] secmat = new int[sec_count][2];
        int max_vert=54;
        String[][] vertex = new String[sec_count][max_vert];
        int secmat_count=0;
        String[][] matr = new String[3][6];
        JFrame frame = new JFrame("Граф");
        int error = 15;


        public void actionPerformed(ActionEvent e) {



            matr[0][0] = forming_1.getText()+" ";
            matr[0][1] = forming_2.getText()+" ";
            matr[0][2] = forming_3.getText()+" ";
            matr[0][3] = forming_4.getText()+" ";
            matr[0][4] = forming_5.getText()+" ";
            matr[0][5] = forming_6.getText()+" ";

            matr[1][0] = defining_left_1.getText()+" ";
            matr[1][1] = defining_left_2.getText()+" ";
            matr[1][2] = defining_left_3.getText()+" ";
            matr[1][3] = defining_left_4.getText()+" ";
            matr[1][4] = defining_left_5.getText()+" ";
            matr[1][5] = defining_left_6.getText()+" ";

            matr[2][0] = defining_right_1.getText()+" ";
            matr[2][1] = defining_right_2.getText()+" ";
            matr[2][2] = defining_right_3.getText()+" ";
            matr[2][3] = defining_right_4.getText()+" ";
            matr[2][4] = defining_right_5.getText()+" ";
            matr[2][5] = defining_right_6.getText()+" ";




            for (int i = 0; i < sec_count; i++) {
                for (int k = 0; k < max_vert; k++) {
                    vertex[i][k] = "";
                }
                for (int k = 0; k < 2; k++) {
                    secmat[i][k] = -10000;
                }
            }
            secmat[0][0] = kx;
            secmat[0][1] = ky;

            char[] matr_form = new char[6];

            for (int i = 0; i < 6; i++) {

                matr_form[i] = ' ';

                if (matr[0][i].charAt(0) != ' ') {

                    matr_form[i] = matr[0][i].charAt(0);

                } else {

                    break;
                }
            }

            int[] matr_form_num = new int[6];
            for (int i = 0; i < 6; i++) {
                matr_form_num[i] = -1;
                if ((matr[2][i]).charAt(0) == 'e' && matr[1][i].length() == 3) {
                    for (int k = 0; k < 6; k++) {
                        if (matr_form[k] == matr[1][i].charAt(0)) {
                            matr_form_num[k] = (int) matr[1][i].charAt(1) - 48;
                        }
                    }
                }
            }

            if (matr_form[0] != ' ' && matr_form_num[0] != -1 &&  matr_form_num[0] != 1 &&  matr_form_num[0] !=0) {

                mult1 = matr_form_num[0];
                ang1 = mult1;
                mult1 *= 100;
            }
            if (matr_form[1] != ' ' && matr_form_num[1] != -1 &&  matr_form_num[1] != 1 &&  matr_form_num[1] !=0) {

                mult2 = matr_form_num[1];
                ang2 = mult2;
                mult2 *= 100;
            }
            if (matr_form[2] != ' ' && matr_form_num[2] != -1&&  matr_form_num[2] != 1 &&  matr_form_num[2] !=0) {

                mult3 = matr_form_num[2];
                ang3 = mult3;
                mult3 *= 100;
            }
            if (matr_form[3] != ' ' && matr_form_num[3] != -1&&  matr_form_num[3] != 1 &&  matr_form_num[3] !=0) {

                mult4 = matr_form_num[3];
                ang4 = mult4;
                mult4 *= 100;
            }
            if (matr_form[4] != ' ' && matr_form_num[4] != -1 &&  matr_form_num[4] != 1 &&  matr_form_num[4] !=0) {
                                mult5 = matr_form_num[4];
                ang5 = mult5;
                mult5 *= 100;
            }
            if (matr_form[5] != ' ' && matr_form_num[5] != -1 &&  matr_form_num[5] != 1 &&  matr_form_num[5] !=0) {

                mult6 = matr_form_num[5];
                ang6 = mult6;
                mult6 *= 100;
            }

            String word = "";

            int tr=1;
            int lt=1;
            if (mult1 != -1) {
                mult1(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            } else if (mult2 != -1) {
                mult2(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            } else if (mult3 != -1) {
                mult3(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            } else if (mult4 != -1) {
                mult4(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            } else if (mult5 != -1) {
                mult5(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            } else if (mult6 != -1) {
                mult6(mult1, mult2, mult3, mult4, mult5, mult6, kx, ky,word,tr,lt);
            }

JOptionPane.showMessageDialog(null, "Итого элементов: "+(secmat_count+1),"Итог",JOptionPane.PLAIN_MESSAGE);
/*
            for(int i=0;i<sec_count;i++){
             if(vertex[i][0]!="" || vertex[i][0]!=" "){
                 int max_l=vertex[i][0].length();
                 int max_c=1;
                 for(int l=1;l<max_vert;l++){
                     if((vertex[i][l].length()!=0)&&(vertex[i][l].length()<max_l)){
                         max_l=vertex[i][l].length();
                     }
                     if((vertex[i][l].length()!=0)){
                         max_c+=1;
                     }

                 }
                 if(max_l>0) {
                    // JOptionPane.showMessageDialog(null, "length: " + max_l + " num: " + max_c + "\n", "Итог", JOptionPane.PLAIN_MESSAGE);
                 }
                 int w=0;
                 for(int l=0;l<max_l;l++){

                     for(int f=0;f<max_c;f++){
                         if(vertex[i][0].charAt(l)==vertex[i][f].charAt(l)){
                             w=l;
                         }
                     }
                 }
                 for(int f=0;f<max_c;f++){
                     char[] tmp = new char[vertex[i][f].length()];
                     vertex[i][f].getChars(w,vertex[i][f].length(),tmp,0);
                     vertex[i][f]="";
                     for(int r=0;r<tmp.length;r++){
                         vertex[i][f]+=tmp[r];
                     }
                 }
             }
             else{
                 break;
             }
            }
*/
            String u="";
        for(int i=0;i<sec_count;i++){

            if(vertex[i][0]==""){
                break;
            };
            for(int h=0;h<max_vert-1;h++){
                if(vertex[i][1]!="") {
                    if(vertex[i][h]!=""&&vertex[i][h]!=" ") {
                        u += vertex[i][h] + " ";
                        if(vertex[i][h+1]!=" "&& vertex[i][h+1]!=""){
                            u+="= ";
                        }else{
                            u+="\n";
                        }

                    }

                }else{
                    break;
                }

            }


        }
            JOptionPane.showMessageDialog(null, u+"\n" ,"Эквивалентные слова",JOptionPane.PLAIN_MESSAGE);
        }


        public void mult1(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr, int lt) {


            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang1) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.BLACK;
            draw.x1 = kx;
            draw.x2 = (int) (kx + ((ang1==2)?-tr:tr)*(100 * Math.sin((ang1 - tr*(tml1 % (ang1))) * angle)));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang1==2)?-tr:tr)*(100 * Math.cos((ang1 - tr*(tml1 % (ang1))) * angle)));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            JOptionPane.showMessageDialog(null, tr+" "+(ang1 - tr*(tml1 % (ang1)))+" "+tr*(tml1 % (ang1))+" "+tml1 % (ang1)+" "+tml1+"\n","Итог",JOptionPane.PLAIN_MESSAGE);
            kx = draw.x2;
            ky = draw.y2;
            mult1 -= 1;
            tml1 -= 1;
            word+=matr[0][0].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;


            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) < error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;

                    if (mult1 != -1) mult1(tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,tr,lt);
                    if (mult2 != -1) mult2(tmp1, lt==2?((ang1!=2&&ang2!=2)?tmp2:ang2==2?tmp2:tmp2+(ang2-3)):tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==2)?-tr:tr,1);
                    if (mult3 != -1) mult3(tmp1, tmp2, lt==3?(ang3==2?tmp3:tmp3+(ang3-3)):tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==3)?-tr:tr,1);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3, lt==4?(ang4==2?tmp4:tmp4+(ang4-3)):tmp4, tmp5, tmp6, kx, ky,word,(lt==4)?-tr:tr,1);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4, lt==5?(ang5==2?tmp5:tmp5+(ang5-3)):tmp5, tmp6, kx, ky,word,(lt==5)?-tr:tr,1);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5, lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,(lt==6)?-tr:tr,1);
                    break;
                }
            }
        }

        public void mult2(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr,int lt) {


            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang2) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.RED;
            draw.x1 = kx;
            draw.x2 = (int) (kx + ((ang2==2)?-tr:tr)*(100 * Math.sin((ang2 - tr*(tml2 % (ang2))) * angle+10)));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang2==2)?-tr:tr)*(100 * Math.cos((ang2 - tr*(tml2 % (ang2))) * angle+10)));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            JOptionPane.showMessageDialog(null, tr+" "+(ang2 - tr*(tml2 % (ang2)))+" "+tr*(tml2 % (ang2))+" "+tml2 % (ang2)+" "+tml2+"\n","Итог",JOptionPane.PLAIN_MESSAGE);

            kx = draw.x2;
            ky = draw.y2;
            mult2 -= 1;
            tml2 -= 1;
            word+=matr[0][1].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;
            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) < error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;
                    if (mult1 != -1) mult1(lt==1?((ang1!=2&&ang2!=2)?tmp1:ang1==2?tmp1:tmp1+(ang1-3)):tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==1)?-tr:tr,2);
                    if (mult2 != -1) mult2(tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word, tr,lt);
                    if (mult3 != -1) mult3(tmp1, tmp2, lt==3?(ang3==2?tmp3:tmp3+(ang3-3)):tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==3)?-tr:tr,lt==2?lt:2);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3, lt==4?(ang4==2?tmp4:tmp4+(ang4-3)):tmp4, tmp5, tmp6, kx, ky,word,(lt==4)?-tr:tr,lt==2?lt:2);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4, lt==5?(ang5==2?tmp5:tmp5+(ang5-3)):tmp5, tmp6, kx, ky,word,(lt==5)?-tr:tr,lt==2?lt:2);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5, lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,(lt==6)?-tr:tr,lt==2?lt:2);
                    break;
                }
            }
        }

        public void mult3(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr,int lt) {


            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang3) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.BLUE;
            draw.x1 = kx;
            draw.x2 = (int) (kx + ((ang3==2)?-tr:tr)*(100 * Math.sin((ang3 - tr*(mult3 % ang3)) * angle+7)));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang3==2)?-tr:tr)*(100 * Math.cos((ang3 - tr*(mult3 % ang3)) * angle+7)));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            kx = draw.x2;
            ky = draw.y2;
            mult3 -= 1;
            tml3 -= 1;
            word+=matr[0][2].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;
            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) < error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;
                    if (mult1 != -1) mult1(lt==1?(ang1==2?tmp1:tmp1+(ang1-3)):tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==1)?-tr:tr,lt==3?lt:3);
                    if (mult2 != -1) mult2(tmp1, lt==2?(ang2==2?tmp2:tmp2+(ang2-3)):tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word, (lt==2)?-tr:tr,lt==3?lt:3);
                    if (mult3 != -1) mult3(tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,tr,3);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3,  lt==4?(ang4==2?tmp4:tmp4+(ang4-3)):tmp4, tmp5, tmp6, kx, ky,word,(lt==4)?-tr:tr,lt==3?lt:3);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4, lt==5?(ang5==2?tmp5:tmp5+(ang5-3)):tmp5, tmp6, kx, ky,word,(lt==5)?-tr:tr,lt==3?lt:3);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5,  lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,(lt==6)?-tr:tr,lt==3?lt:3);
                    break;
                }
            }
        }

        public void mult4(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr,int lt) {


            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang4) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.GREEN;
            draw.x1 = kx;
            draw.x2 = (int) (kx + ((ang4==2)?-tr:tr)*(100 * Math.sin((ang4 - tr*(mult4 % ang4)) * angle)+2));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang4==2)?-tr:tr)*(100 * Math.cos((ang4 - tr*(mult4 % ang4)) * angle)+2));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            kx = draw.x2;
            ky = draw.y2;
            mult4 -= 1;
            tml4 -= 1;
            word+=matr[0][3].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;
            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) < error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;
                    if (mult1 != -1) mult1(lt==1?(ang1==2?tmp1:tmp1+(ang1-3)):tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==1)?-tr:tr,lt==4?lt:4);
                    if (mult2 != -1) mult2(tmp1, lt==2?(ang2==2?tmp2:tmp2+(ang2-3)):tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word, (lt==2)?-tr:tr,lt==4?lt:4);
                    if (mult3 != -1) mult3(tmp1, tmp2, lt==3?(ang3==2?tmp3:tmp3+(ang3-3)):tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==3)?-tr:tr,lt==4?lt:4);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,tr,4);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4, lt==5?(ang5==2?tmp5:tmp5+(ang5-3)):tmp5, tmp6, kx, ky,word,(lt==5)?-tr:tr,lt==4?lt:4);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5, lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,(lt==6)?-tr:tr,lt==4?lt:4);
                    break;
                }
            }
        }

        public void mult5(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr,int lt) {

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang5) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.YELLOW;
            draw.x1 = kx;
            draw.x2 = (int) (kx + ((ang5==2)?-tr:tr)*(100 * Math.sin((ang5 - tr*(mult5 % ang5)) * angle)+8));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang5==2)?-tr:tr)*(100 * Math.cos((ang5 - tr*(mult5 % ang5)) * angle)+8));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            kx = draw.x2;
            ky = draw.y2;
            mult5 -= 1;
            tml5 -= 1;
            word+=matr[0][4].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;
            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) < error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;
                    if (mult1 != -1) mult1(lt==1?(ang1==2?tmp1:tmp1+(ang1-3)):tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==1)?-tr:tr,lt==5?lt:5);
                    if (mult2 != -1) mult2(tmp1, lt==2?(ang2==2?tmp2:tmp2+(ang2-3)):tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word, (lt==2)?-tr:tr,lt==5?lt:5);
                    if (mult3 != -1) mult3(tmp1, tmp2, lt==3?(ang3==2?tmp3:tmp3+(ang3-3)):tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==3)?-tr:tr,lt==5?lt:5);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3, lt==4?(ang4==2?tmp4:tmp4+(ang4-3)):tmp4, tmp5, tmp6, kx, ky,word,(lt==4)?-tr:tr,lt==5?lt:5);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,tr,5);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5, lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,(lt==6)?-tr:tr,lt==5?lt:5);
                    break;
                }
            }
        }

        public void mult6(int tml1, int tml2, int tml3, int tml4, int tml5, int tml6, int kx, int ky,String word,int tr,int lt) {


            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            double angle = (360 / ang6) * (Math.PI / 180);
            Drawing draw = new Drawing();
            draw.setBackground(Color.WHITE);
            draw.color = Color.MAGENTA;
            draw.x1 = kx;
            draw.x2 = (int) (kx +((ang6==2)?-tr:tr)*(100 * Math.sin((ang6 - tr*(mult6 % ang6)) * angle)));
            draw.y1 = ky;
            draw.y2 = (int) (ky - ((ang6==2)?-tr:tr)*(100 * Math.cos((ang6 - tr*(mult6 % ang6)) * angle)));
            for (int d = 0; d < sec_count; d++) {
                if (Math.abs(secmat[d][0] - draw.x2) < error && Math.abs(secmat[d][1] - draw.y2) < error) {
                    draw.x2 = secmat[d][0];
                    draw.y2 = secmat[d][1];
                }
            }
            frame.add(draw);
            frame.setSize(600, 600);
            frame.setVisible(true);
            kx = draw.x2;
            ky = draw.y2;
            mult6 -= 1;
            tml6 -= 1;
            word+=matr[0][5].charAt(0);
            int tmp1 = tml1;
            int tmp2 = tml2;
            int tmp3 = tml3;
            int tmp4 = tml4;
            int tmp5 = tml5;
            int tmp6 = tml6;
            for (int j = 0; j < sec_count; j++) {
                if (Math.abs(secmat[j][0] - kx) < error && Math.abs(secmat[j][1] - ky) <error) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    break;
                } else if ((secmat)[j][0] == -10000 && (secmat)[j][1] == -10000) {
                    for(int l=0;l<max_vert;l++){
                        if(vertex[j][l]==""){
                            vertex[j][l]=word;
                            break;
                        }
                    }
                    (secmat)[j][0] = kx;
                    (secmat)[j][1] = ky;
                    secmat_count +=1;
                    if (mult1 != -1) mult1(lt==1?(ang1==2?tmp1:tmp1+(ang1-3)):tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==1)?-tr:tr,lt==6?lt:6);
                    if (mult2 != -1) mult2(tmp1, lt==2?(ang2==2?tmp2:tmp2+(ang2-3)):tmp2, tmp3, tmp4, tmp5, tmp6, kx, ky,word, (lt==2)?-tr:tr,lt==6?lt:6);
                    if (mult3 != -1) mult3(tmp1, tmp2,lt==3?(ang3==2?tmp3:tmp3+(ang3-3)):tmp3, tmp4, tmp5, tmp6, kx, ky,word,(lt==3)?-tr:tr,lt==6?lt:6);
                    if (mult4 != -1) mult4(tmp1, tmp2, tmp3,  lt==4?(ang4==2?tmp4:tmp4+(ang4-3)):tmp4, tmp5, tmp6, kx, ky,word,(lt==4)?-tr:tr,lt==6?lt:6);
                    if (mult5 != -1) mult5(tmp1, tmp2, tmp3, tmp4,  lt==5?(ang5==2?tmp5:tmp5+(ang5-3)):tmp5, tmp6, kx, ky,word,(lt==5)?-tr:tr,lt==6?lt:6);
                    if (mult6 != -1) mult6(tmp1, tmp2, tmp3, tmp4, tmp5,  lt==6?(ang6==2?tmp6:tmp6+(ang6-3)):tmp6, kx, ky,word,tr,6);
                    break;
                }
            }
        }



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
