package main

import (
  "os"
)

func main() {
  a := App{}
  a.Initialize(
    os.Getenv("PW_DB_USERNAME"),
    os.Getenv("PW_DB_PASSWORD"),
    os.Getenv("PW_DB_NAME"))

  a.Run(":8080")
}
