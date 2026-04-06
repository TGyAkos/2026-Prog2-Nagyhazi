## Terv - UML diagramok

### Osztálydiagram

```mermaid
classDiagram
    class MessageFile {
        +MessageFile()  
        +loadFile(file_name: std::string) std::string
        +saveToFile(message: std::string)
        +~MessageFile()
    }
    class CipherFile {
        -output_file_name: const char* : statikus
        +CipherFile()
        +loadFile(file_name: std::string) CipherList* \n
        +saveToFile(list: CipherList*)
        +~CipherFile()
    }

    class CipherFactory {
        <<singleton>>
        -ciphers : std::unordered_map~std::string, std::function< Cipher>~
        -parseCipherString(cipher_string: std::string) std::vector~std::string~
        +getInstance() CipherFactory& : statikus
        +registerCipher(cipher_name: const char*, func: std::function~Cipher~)
        +createCipher(cipher_string: std::string) Cipher* \n
        +cipherExists(const char* cipher_name) bool const 
        +~CipherFactory()
    }
    
    class Registrar {
        <<template>>
        Registrar(cipher_name: const char*)
    }
        
    class Cipher {
        <<interface>>
        +encode(message: std::string)* std::string
        +decode(ciphertext: std::string)* std::string
        +clone()* Cipher*
        +getCipherString()* std::string
        +~Cipher()*
    }
    
    class CaesarCipher {
        -shift : int
        +CaesarCipher(shift: int)
        +CaesarCipher(shift_as_string: std::string)
        +encode(message: std::string) std::string
        +decode(ciphertext: std::string) std::string
        +clone() Cipher* \n
        +getCipherString() std::string
        +~CaesarCipher()
    }
    
    class MyCipher {
        -key : std::string
        -offset : int
        +MyCipher(key: const char*, offset: int)
        +MyCipher(key_as_string: std::string, offset_as_string: std::string)
        +encode(message: std::string) std::string
        +decode(ciphertext: std::string) std::string
        +clone() Cipher* \n
        +getCipherString() std::string
        +~MyCipher()
    }
    
    class TranspositionCipher {
        -matrix_size : int
        +TranspositionCipher(matrix_size: int)
        +TranspositionCipher(matrix_size_as_string: std::string)
        +encode(message: std::string) std::string
        +decode(ciphertext: std::string) std::string
        +clone() Cipher* \n
        +getCipherString() std::string
        +~TranspositionCipher()
    }

    class CipherList {
        -ciphers : std::vector~Cipher*~
        +CipherList()
        +CipherList(other: const CipherList&)
        +operator=(other: const CipherList&) CipherList&
        +operator[](idx: size_t) Cipher&
        +operator[](idx: size_t) const Cipher& const
        +add(cipher: Cipher*) void
        +encode(message: std::string) std::string
        +decode(ciphertext: std::string) std::string
        +clone() Cipher* \n
        +~CipherList()
    }
    


    CipherList ..> Cipher
    CipherList o-- "0..* -ciphers" Cipher

    Cipher <|-- CaesarCipher
    Cipher <|-- MyCipher
    Cipher <|-- TranspositionCipher

    CipherFactory ..> Cipher
    CipherFactory o-- "0..* -ciphers" Cipher
    Registrar ..> CipherFactory

    CipherFile ..> CipherList
    CipherFile ..> CipherFactory


```

A CipherFile::saveToFile() függvény a dinamikusan változó kódolások helyes működése végett van implementálva.

### Sekvenciadiagramok

A main függvény lefutása előtt a következő műveletek történnek:
```mermaid
sequenceDiagram
    autonumber
    participant Static Initialization
    create participant Registrar
    participant CipherFactory
    Static Initialization ->>+ Registrar : Registrar<Cipher>(cipher_name)
    Registrar ->>+ CipherFactory : getInstance()
    CipherFactory -->>- Registrar : CipherFactory&
    Registrar ->>+ CipherFactory : registerCipher(cipher_name, []() -> Cipher*)
    deactivate CipherFactory
    destroy Registrar
    Registrar ->> Static Initialization : Registrar object created, cipher registered
    
```

A main függvény végrehajtása során a következő műveletek történnek:
```mermaid
sequenceDiagram
    autonumber
    participant main
    create participant MessageFile
    main ->> MessageFile : MessageFile()
    main ->>+ MessageFile : loadfile(file_name)
    MessageFile -->>- main : message_string
    create participant CipherFile
    participant CipherFactory
    main ->> CipherFile : CipherFile()
    main ->>+ CipherFile : loadfile(file_name)
    create participant CipherList
    CipherFile ->> CipherList : CipherList()
    loop for each cipher_string in file
        CipherFile ->>+ CipherFactory : createCipher(cipher_string)
        CipherFactory ->> CipherFactory : parseCipherString(cipher_string)
        create participant Cipher
        CipherFactory ->> Cipher : ciphers[cipher_name](cipher_parameters)
        Cipher -->> CipherFactory : Cipher*
        CipherFactory -->>- CipherFile : Cipher*
        CipherFile ->>+ CipherList : add(Cipher*)
        deactivate CipherList
    end
    CipherList -->> CipherFile : CipherList*
    CipherFile -->>- main : CipherList*
    main ->>+ CipherList : encode(message_string)/decode(message_string)

    loop for each cipher in CipherList
        CipherList ->>+ Cipher : encode/decode(message_string)
        Cipher -->>- CipherList : coded_message_string
    end

    CipherList -->>- main : coded_message_string
    main ->>+ MessageFile : saveToFile(coded_message_string)
    deactivate MessageFile
    main ->>+ CipherFile : saveToFile(CipherList*)
    loop for each cipher in CipherList
        CipherFile ->>+ Cipher : getCipherString()
        Cipher -->>- CipherFile : cipher_string
        CipherFile ->> CipherFile : append cipher_string to save_string
    end
    deactivate CipherFile
```
