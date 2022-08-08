/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Auxiliar;

import java.awt.Graphics;
import java.io.Serializable;
import javax.swing.ImageIcon;

import Controler.Tela;


public class Desenho implements Serializable {
    static Tela jCenario1;
    public static void setCenario(Tela umJCenario) {
        jCenario1 = umJCenario;
    }

    public static Tela getCenario() {
        return jCenario1;
    }

    public static Graphics getGraphicsDaTela() {
        return jCenario1.getGraphicsBuffer();
    }
    
    public static void desenhar(ImageIcon iImage, int iColuna, int iLinha) {
        iImage.paintIcon(jCenario1, getGraphicsDaTela(),iColuna * Consts.CELL_SIDE, iLinha * Consts.CELL_SIDE);
    }
}
