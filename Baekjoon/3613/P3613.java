import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class P3613 {
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String input = br.readLine();

        // if input has '_' or small letter, c++
        // if input dosen't have '_' and has only alphabet, java
        // if input has '_' and big letter, throw Error! 

        int len = input.length();
        boolean hasUnderScore = false;
        boolean hasSmallLetter = false;
        boolean hasBigLetter = false;
        boolean isError = false;
        for(int i=0; i<len; i++) {
            if(input.charAt(i) == '_') {hasUnderScore = true;}
            else if (input.charAt(i) >= 'A' && input.charAt(i) <= 'Z') {hasBigLetter = true;}
            else if (input.charAt(i) >= 'a' && input.charAt(i) <= 'z') {hasSmallLetter = true;}
            else {isError = true;}
        }

        if(hasUnderScore && hasBigLetter) {isError = true;}
        if(hasUnderScore && !hasBigLetter && !hasSmallLetter) {isError = true;}


        if(isError) {
            sb.append("Error!");
        } else {
            if(hasUnderScore || (hasSmallLetter && !hasBigLetter)) {
                if(input.charAt(0) == '_' || input.charAt(len-1) == '_') {
                    sb.append("Error!");
                } else {
                    // C type
                    boolean isBig = false;
                    for(int i=0; i<len; i++) {
                        if(input.charAt(i) == '_') {
                            if(isBig) {
                                isError = true;
                                sb=new StringBuilder();
                                sb.append("Error!");
                                break;
                            }
                            isBig = true;
                        } else {
                            if(isBig) {
                                sb.append((char)(input.charAt(i) - 'a' + 'A'));
                                isBig = false;
                            } else{
                                sb.append(input.charAt(i));
                            }
                        }
                    }
                }
            } else {
                // Java Type
                if(input.charAt(0) >= 'A' && input.charAt(0) <= 'Z') {
                    isError = true;
                    sb.append("Error!");
                } else {
                    for(int i=0; i<len ;i++) {
                        if(input.charAt(i) >= 'A' && input.charAt(i) <= 'Z') {
                            sb.append("_").append((char)(input.charAt(i) - 'A' + 'a'));
                        } else {
                            sb.append(input.charAt(i));
                        }
                    }
                }

            }
        }
        bw.write(sb.toString());
        br.close();
        bw.close();

    }
}