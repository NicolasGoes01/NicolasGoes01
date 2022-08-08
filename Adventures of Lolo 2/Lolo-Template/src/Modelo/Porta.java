package Modelo;

import java.io.Serializable;

public class Porta extends Elemento implements Serializable {
    public Porta(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bTransponivel = true;
    }
}
