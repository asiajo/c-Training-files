#include <string>
#include <iostream>

std::string encrypt(std::string text, int n)
{
    std::string ntext;
    if(n>0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<text.size(); j = j+2)
                ntext += text[j];
            for(int k=0; k<text.size(); k = k+2)
                ntext += text[k];
            text = ntext;
            ntext = "";
        }
    }
    return text;
}

std::string decrypt(std::string encryptedText, int n)
{

    std::string dtext;
    if(n>0)
    {
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<encryptedText.size()/2; j++)
                {
                    dtext += encryptedText[encryptedText.size()/2 + j];
                    dtext += encryptedText[j];
                }
            // when the number of characters in the string is odd the last one stays always
            // on the last place
            if(encryptedText.size()%2)
                dtext += encryptedText.back();
            encryptedText = dtext;
            dtext = "";
        }
    }
    return encryptedText;
}


int main()
{
    std::string text{"This is a test!"};
    std::cout << "This is original text: " << text << std::endl;
    std::string textEncrypted = encrypt(text,1);
    std::cout << "This is encrypted text: " << textEncrypted << std::endl;
    std::cout << "This is decrypted text: " << decrypt(textEncrypted,1) << std::endl;
    return 0;
}
