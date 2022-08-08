package Modelo;

import java.io.Serializable;

public class Planta extends Elemento implements Serializable {

    public Planta(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = false;
    }
}
