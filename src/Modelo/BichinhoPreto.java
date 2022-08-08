package Modelo;

import java.io.Serializable;
import java.util.Random;

public class BichinhoPreto extends Elemento implements Serializable {
    public BichinhoPreto(String sNomeImagePNG) {
        super(sNomeImagePNG);
        this.bMortal = true;
        this.bTransponivel = true;
    }
}
