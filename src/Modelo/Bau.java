package Modelo;

import java.io.Serializable;

public class Bau extends Elemento implements Serializable {
    private boolean isOpen;
    private boolean enterOpen;
    public Bau(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = true;
        isOpen = false;
        enterOpen = false;
    }

    public void setOpen(boolean open) {
        this.isOpen = open;
    }

    public boolean getOpen() {
        return this.isOpen;
    }

    public boolean isEnterOpen() {
        return enterOpen;
    }

    public void setEnterOpen(boolean enterOpen) {
        this.enterOpen = enterOpen;
    }
}
