package main

import (
	"database/sql"
	"errors"
)

type user struct {
	Id    int    `json:"id"`
	Name  string `json:"name"`
	Email string `json:"email"`
}
