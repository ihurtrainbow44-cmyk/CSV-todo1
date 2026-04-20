CREATE DATABASE ToDoDB;
GO

USE ToDoDB;
GO

CREATE TABLE Tasks (
    Id INT PRIMARY KEY IDENTITY(1,1),
    Title NVARCHAR(255) NOT NULL,
    Description NVARCHAR(500),
    Status NVARCHAR(50) NOT NULL
);

INSERT INTO Tasks (Title, Description, Status)
VALUES 
('Купить хлеб', 'Сходить в магазин', 'active'),
('Сделать ДЗ', 'ООП проект', 'done');

SELECT * FROM Tasks;

UPDATE Tasks
SET Status = 'done'
WHERE Id = 1;

DELETE FROM Tasks
WHERE Id = 1;

SELECT * FROM Tasks
WHERE Status = 'active';


SELECT COUNT(*) AS TotalTasks FROM Tasks;