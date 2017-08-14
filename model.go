package main

import (
	"database/sql"
	"fmt"
	"strconv"
)

type user struct {
	ID    string    `json:"id"`
	Name  string `json:"name"`
	Email string `json:"email"`
}

func (u *user) getUserByID(db *sql.DB) error {
	return db.QueryRow("SELECT name, email FROM users WHERE id=?",
		u.ID).Scan(&u.Name, &u.Email)
}

func (u *user) getUserByEmail(db *sql.DB) error {
	return db.QueryRow("SELECT name, id FROM users WHERE email=?",
		u.Email).Scan(&u.Name, &u.ID)
}

func (u *user) createUser(db *sql.DB) error {
  statement := fmt.Sprintf(
    "INSERT INTO users(name, email) VALUES('%s', '%s')",
    u.Name, u.Email)
	res, err := db.Exec(statement)
  if err != nil {
      return err
  }

	lastInsertID, err := res.LastInsertId()
  if err != nil {
      return err
  }

	u.ID = strconv.Itoa(int(lastInsertID))

  return nil
}
