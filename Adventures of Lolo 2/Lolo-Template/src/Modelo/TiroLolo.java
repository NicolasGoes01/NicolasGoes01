package Modelo;

import Auxiliar.Desenho;

import java.io.Serializable;
import java.awt.event.KeyEvent;

public class TiroLolo extends Elemento implements Serializable {
    private int lastKeyEvent;
    public TiroLolo(String sNomeImagePNG, int lastKeyEvent) {
        super(sNomeImagePNG);
        this.bMortal = true;
        this.lastKeyEvent = lastKeyEvent;
    }

    @Override
    public void autoDesenho() {
        super.autoDesenho();
        if (lastKeyEvent == KeyEvent.VK_UP) {
            if(!this.moveUp()) {
                Desenho.getCenario().removeTiroLolo(this);
            }
        }
        else if (lastKeyEvent == KeyEvent.VK_DOWN) {
            if(!this.moveDown()) {
                Desenho.getCenario().removeTiroLolo(this);
            }
        }
        else if (lastKeyEvent == KeyEvent.VK_LEFT) {
            if(!this.moveLeft()) {
                Desenho.getCenario().removeTiroLolo(this);
            }
        }
        else if (lastKeyEvent == KeyEvent.VK_RIGHT) {
            if(!this.moveRight()) {
                Desenho.getCenario().removeTiroLolo(this);
            }
        }
    }

}
