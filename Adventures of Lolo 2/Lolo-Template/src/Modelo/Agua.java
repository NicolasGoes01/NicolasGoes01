package Modelo;

import java.io.Serializable;

public class Agua extends Elemento implements Serializable {
    public Agua(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = false;
    }
}
