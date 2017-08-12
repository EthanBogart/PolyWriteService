package main

var DB_USERNAME string
var DB_PASSWORD string
var DB_NAME string

func main() {
  a := App{}
  a.Initialize(
    DB_USERNAME,
    DB_PASSWORD,
    DB_NAME)

  a.Run(":8080")
}
