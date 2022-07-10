#include "tests.h"

Tests::Tests(QObject *parent) : QObject(parent)
{

}

void Tests::testEncryption()
{
    const QString alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const QString alphabet_upper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    caesarCipher* caesar = new caesarCipher(alphabet, alphabet_upper);

    QCOMPARE(caesar->encryption("Съешь же ещё этих мягких французских булок, да выпей чаю.", 3),
             "Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.");
    QCOMPARE(caesar->encryption("Ещё трава полна прозрачных слёз, и гром вдали гремит раскатом.", 5),
             "Йюк чхеже фурте фхумхеьтаъ цркм, н зхус жиерн зхйснч хецпечус.");
    QCOMPARE(caesar->encryption("В сенях пахло свежими яблоками и висели волчьи и лисьи шкуры.", 7),
             "И шлфёь цжьтх шилнпуп ёзтхсжуп п ипшлтп ихтюгп п тпшгп ясъчв.");
    QCOMPARE(caesar->encryption("Люди сильно проголодались, лошади тоже нуждались в отдыхе?", 10),
             "Хзнт ытхёчш щъшмшхшнйхтыё, хшвйнт ьшро чэрнйхтыё л шьнеяо?");
    QCOMPARE(caesar->encryption("Ни души не попалось на пути, ни огня за ставнями!", 13),
             "Ъх раех ъс ьыьмшыюи ъм ьаях, ъх ыпъл фм юямоълщх!");
    QCOMPARE(caesar->encryption("Самый короткий путь к сердцу — это искренность.", 39),
             "Чётбп рфцфшроп хщшв р чкцйьщ — гшф очрцкууфчшв.");
    QCOMPARE(caesar->encryption("Все люди зануды, кроме тех случаев, когда мы в них нуждаемся.", 50),
             "Твх ьофщ шрюдфл, ыбяэх гхё вьдзрхт, ыяуфр эл т ющё юдчфрхэвп.");
}

void Tests::testDecryption()
{
    const QString alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const QString alphabet_upper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    caesarCipher* caesar = new caesarCipher(alphabet, alphabet_upper);

    QCOMPARE(caesar->decryption("Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.", 3),
             "Съешь же ещё этих мягких французских булок, да выпей чаю.");
    QCOMPARE(caesar->decryption("Йюк чхеже фурте фхумхеьтаъ цркм, н зхус жиерн зхйснч хецпечус.", 5),
             "Ещё трава полна прозрачных слёз, и гром вдали гремит раскатом.");
    QCOMPARE(caesar->decryption("И шлфёь цжьтх шилнпуп ёзтхсжуп п ипшлтп ихтюгп п тпшгп ясъчв.", 7),
             "В сенях пахло свежими яблоками и висели волчьи и лисьи шкуры.");
    QCOMPARE(caesar->decryption("Хзнт ытхёчш щъшмшхшнйхтыё, хшвйнт ьшро чэрнйхтыё л шьнеяо?", 10),
             "Люди сильно проголодались, лошади тоже нуждались в отдыхе?");
    QCOMPARE(caesar->decryption("Ъх раех ъс ьыьмшыюи ъм ьаях, ъх ыпъл фм юямоълщх!", 13),
             "Ни души не попалось на пути, ни огня за ставнями!");
    QCOMPARE(caesar->decryption("Чётбп рфцфшроп хщшв р чкцйьщ — гшф очрцкууфчшв.", 39),
             "Самый короткий путь к сердцу — это искренность.");
    QCOMPARE(caesar->decryption("Твх ьофщ шрюдфл, ыбяэх гхё вьдзрхт, ыяуфр эл т ющё юдчфрхэвп.", 50),
             "Все люди зануды, кроме тех случаев, когда мы в них нуждаемся.");
}

void Tests::testExponentiation()
{
    DiffieHellmanProtocol diffie_hellman;

    QCOMPARE(diffie_hellman.exponentiation(5, 6, 23), "8");
    QCOMPARE(diffie_hellman.exponentiation(5, 15, 23), "19");
    QCOMPARE(diffie_hellman.exponentiation(19, 6, 23), "2");
    QCOMPARE(diffie_hellman.exponentiation(8, 15, 23), "2");

    QCOMPARE(diffie_hellman.exponentiation(12, 123, 101), "35");
    QCOMPARE(diffie_hellman.exponentiation(12, 345, 101), "60");
    QCOMPARE(diffie_hellman.exponentiation(60, 123, 101), "62");
    QCOMPARE(diffie_hellman.exponentiation(35, 345, 101), "62");

    QCOMPARE(diffie_hellman.exponentiation(3, 97, 353), "40");
    QCOMPARE(diffie_hellman.exponentiation(3, 233, 353), "248");
    QCOMPARE(diffie_hellman.exponentiation(248, 97, 353), "160");
    QCOMPARE(diffie_hellman.exponentiation(40, 233, 353), "160");

    QCOMPARE(diffie_hellman.exponentiation(48, 765, 413), "41");
    QCOMPARE(diffie_hellman.exponentiation(48, 543, 413), "405");
    QCOMPARE(diffie_hellman.exponentiation(405, 765, 413), "370");
    QCOMPARE(diffie_hellman.exponentiation(41, 543, 413), "370");
}
