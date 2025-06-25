public class javaBasico {

public static void main (String [] args) {
    System.out.println("Hello, World!");
    String primeiroNome = "Arthur";
    String segundoNome = "Rosin";

    String nomeCompleto =  nomeCompleto (primeiroNome, segundoNome);
    System.out.println(nomeCompleto);
}

public static String nomeCompleto (String primeiroNome, String segundoNome) {
    return "Resultado: " + primeiroNome.concat(" ").concat(segundoNome);
    //Duas maneiras de realizar concatenação. Usando o método .concat e usando "+"

}

} 