package main

import (
	"database/sql"
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
  err := db.QueryRow(
    "INSERT INTO user(id, name, email) VALUES(uuid(), $1, $2)",
    u.Name, u.Email).Scan(&u.ID)

  if err != nil {
    return err
  }

  return nil
}
