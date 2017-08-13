package main

import (
	"database/sql"
	"fmt"
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

func (u *user) createUser(db *sql.DB) error {
  statement := fmt.Sprintf(
    "INSERT INTO users(name, email) VALUES('%s', '%s')",
    u.Name, u.Email)
	_, err := db.Exec(statement)
  if err != nil {
      return err
  }

  if err != nil {
    return err
  }

	err = db.QueryRow("SELECT MAX(ID) from users").Scan(&u.ID)
  if err != nil {
      return err
  }

  return nil
}
