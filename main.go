package main

import (
  "os"
  "fmt"
)

func main() {
  a := App{}
  a.Initialize(
    os.Getenv("PW_DB_USERNAME"),
    os.Getenv("PW_DB_PASSWORD"),
    os.Getenv("PW_DB_NAME"))

  fmt.Println("PolyWrite server running on port 8080...")
  a.Run(":8080")
}
