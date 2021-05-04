package main

import (
	"crypto/rc4"
	"encoding/hex"
	"fmt"
)

const encstr string = "e328385c0a94d9f0379771744e4a4993743fbfa7a3869068b5d42483"

func main() {
	key := []byte("BI0X")
	c, _ := rc4.NewCipher(key)
	var usrinpt string
	fmt.Println("Please input flag: ")
	fmt.Scanln(&usrinpt)
	src := []byte(usrinpt)
	dst := src
	c.XORKeyStream(dst, src)
	//fmt.Println(string(dst))
	hex_string_data := hex.EncodeToString(dst)
	if hex_string_data == encstr {
		fmt.Println("Right! Your input is flag!")
	} else {
		fmt.Println("Wrong Answer!")
	}
}
