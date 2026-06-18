	-- Lau Yee Wen A23CS0099 (Section 1)
    -- Poh Lok Yee A23CS0262 (Section 1)
    -- Assignment 1
    -- Task 1: Database Creation and Integrity Constraints (CLO1)
    SET SQL_SAFE_UPDATES = 0;
    
	-- 1. Create a database
    CREATE DATABASE hostel_mgmt_PohLokYee_LauYeeWen; 
    USE hostel_mgmt_PohLokYee_LauYeeWen;
    
    -- 2&3&4. Create tables, apply aonstriants
    -- room_types table
    CREATE TABLE IF NOT EXISTS room_types(
		type_id INT PRIMARY KEY AUTO_INCREMENT,
        type_name VARCHAR (50) NOT NULL UNIQUE,
        rent DECIMAL (7,2) NOT NULL,
        deposit  DECIMAL (7,2) NOT NULL,
        capacity INT NOT NULL
    );
    
    -- rooms table
    CREATE TABLE IF NOT EXISTS rooms(
		room_id INT PRIMARY KEY AUTO_INCREMENT,
		type_id INT NOT NULL,
        room_no VARCHAR (10) NOT NULL UNIQUE,
        floor_no INT NOT NULL,
        is_occupied BOOLEAN DEFAULT FALSE,
        FOREIGN KEY (type_id) REFERENCES room_types(type_id)
	);
    
    -- student table
    CREATE TABLE IF NOT EXISTS students(
		student_id INT PRIMARY KEY AUTO_INCREMENT,
		room_id INT, 
		fname VARCHAR(50) NOT NULL,
		lname VARCHAR(50) NOT NULL,
		status ENUM('ACTIVE', 'NON_ACTIVE') NOT NULL DEFAULT 'NON_ACTIVE',
		checkin_date DATE,
		FOREIGN KEY (room_id) REFERENCES rooms(room_id)
	);
    
    -- maintenance table
    CREATE TABLE IF NOT EXISTS maintenance(
		maint_id INT PRIMARY KEY AUTO_INCREMENT,
        room_id INT,
        issue_desc VARCHAR(255) NOT NULL,
        severity ENUM('LOW','MEDIUM','HIGH') NOT NULL,
        status ENUM('OPEN','RESOLVED') NOT NULL DEFAULT 'OPEN',
        reported_on DATE NOT NULL,
        resolved_on DATE ,
        FOREIGN KEY(room_id) REFERENCES rooms(room_id)
    );
    
    -- payment table
    CREATE TABLE IF NOT EXISTS payments(
		payment_id INT PRIMARY KEY AUTO_INCREMENT,
		student_id INT NOT NULL,
		amount DECIMAL(6,2) NOT NULL,
		paid_on DATE NOT NULL,
		method ENUM('CASH','FPX','CARD','TNG') NOT NULL,
		note VARCHAR(255),
		FOREIGN KEY (student_id) REFERENCES students(student_id)
    );
    
    -- 5. Demonstrate schema maintenance
    -- Add an email column to students and mark it UNIQUE
    ALTER TABLE students
    ADD email VARCHAR(100) UNIQUE;
    
     -- Create a temporary test table and drop it safely
    CREATE TABLE temp_test (id INT);
    DROP TABLE temp_test;
    
    
    -- Task 2 – Data Manipulation and Filtering (CLO2)
    -- 1. Data Insertion (DML) with at least 10 rows realistic and varied data per table 
    
	-- room_types table
    INSERT INTO room_types (type_name, rent, deposit, capacity) VALUES
		('Single Standard', 450.00, 200.00, 1),
        ('Single Plus', 550.00, 250.00, 1),
        ('Single Premium', 650.00, 350.00, 1),
        ('Double Standard', 750.00, 400.00, 2),
        ('Double Plus', 800.00, 400.00, 2),
        ('Double Premium', 850.00, 450.00, 2),
        ('Premium Loft', 1000.00, 500.00, 2),
        ('Premium Suite', 1300.00, 650.00, 2),
        ('Family Standard', 1600.00, 800.00, 4),
        ('Family Deluxe', 2000.00, 1200.00, 4);
        
	-- rooms table
	INSERT INTO rooms (type_id, room_no, floor_no, is_occupied) VALUES
		(1, 'A101', 1, FALSE),
        (2, 'A102', 1, FALSE),
        (3, 'A203', 2, FALSE),
        (4, 'B201', 2, FALSE),
        (5, 'B202', 2, FALSE),
		(6, 'B305', 3, FALSE),
        (7, 'C108', 1, FALSE),
        (8, 'C118', 1, FALSE),
        (9, 'C405', 4, FALSE),
        (10, 'C102', 1, FALSE);
	
    -- student table
	INSERT INTO students (room_id, fname, lname, status, checkin_date, email) VALUES
		(1, 'Adib', 'Zikri', 'ACTIVE', '2025-01-01', 'adib@graduate.utm.my'),
		(2, 'Yee Wen', 'Lau', 'ACTIVE', '2025-01-03', 'lauyeewen@graduate.utm.my'),
		(NULL, 'Lok Yee', 'Poh', 'NON_ACTIVE', '2025-02-03', 'pohlokyee@graduate.utm.my'),
		(4, 'Yasmin', 'Batrisya', 'ACTIVE', '2025-02-01', 'yasmin@graduate.utm.my'),
		(5, 'Cheryl', 'Cheong', 'ACTIVE', '2025-01-09', 'cheryl@graduate.utm.my'),
		(NULL, 'Aqmal', 'Azizi', 'NON_ACTIVE', '2025-03-05', 'aqmal@graduate.utm.my'),
		(7, 'Brendan', 'Ng', 'ACTIVE', '2025-01-02', 'brendan@graduate.utm.my'),
		(8, 'Sabrina', 'Heng', 'ACTIVE', '2025-01-01', 'sabrina@graduate.utm.my'),
		(9, 'Jane', 'Woo', 'ACTIVE', '2025-01-04', 'jane@graduate.utm.my'),
		(NULL, 'Jia Jia', 'Lee', 'NON_ACTIVE', '2025-01-05', 'leejiajia@graduate.utm.my');

	-- maintenance table
	INSERT INTO maintenance (room_id, issue_desc, severity, status, reported_on, resolved_on) VALUES
		(1, 'Broken desk', 'MEDIUM', 'RESOLVED', '2025-06-10', '2025-06-15'),
		(2, 'Water leak in bathroom', 'HIGH', 'RESOLVED', '2025-06-19', '2025-06-20'),
		(3, 'Aircond not cold', 'LOW', 'RESOLVED', '2025-07-04', '2025-07-10'),
        (4, 'Door lock issue', 'MEDIUM', 'RESOLVED', '2025-07-08', '2025-07-10'),
        (5, 'Noisy neighbors', 'LOW', 'RESOLVED', '2025-08-21', '2025-08-28'),
        (6, 'Fan not working', 'MEDIUM', 'RESOLVED', '2025-09-23','2025-09-26' ),
        (7, 'Leaking pipe', 'MEDIUM', 'OPEN', '2025-10-21', NULL),
        (8, 'Broken light bulb', 'LOW', 'OPEN', '2025-10-21', NULL),
        (9, 'Unstable WiFi connection', 'LOW', 'OPEN', '2025-10-24', NULL),
        (10, 'Bathroom door jammed', 'HIGH', 'OPEN', '2025-11-01', NULL);
        
	-- payments table
	INSERT INTO payments (student_id, amount, paid_on, method, note) VALUES
	    (1, 450.00, '2025-01-01', 'CASH', 'January Rent'),
        (2, 550.00, '2025-01-05', 'FPX', 'January Rent'),
        (3, 650.00, '2025-02-01', 'CARD', 'February Rent'),
        (4, 750.00, '2025-02-05', 'TNG', 'February Rent'),
        (5, 800.00, '2025-01-10', 'CASH', 'January Rent'),
        (6, 850.00, '2025-03-15', 'FPX', 'March Rent'),
        (7, 1000.00, '2025-01-20', 'CARD', 'January Rent'),
        (8, 1300.00, '2025-02-01', 'TNG', 'February Rent'),
        (9, 1600.00, '2025-01-25', 'CASH', 'January Rent'),
        (10, 2000.00, '2025-02-10', 'FPX', 'February Rent');
        
        
	-- 2. UPDATE and DELETE Operations
    -- UPDATE OPERATIONS
	UPDATE rooms
    INNER JOIN students ON rooms.room_id = students.room_id
    SET rooms.is_occupied = TRUE 
    WHERE students.status ='ACTIVE';
    
    -- DELETE OPERATION
    DELETE FROM maintenance
    WHERE status ='RESOLVED'
		AND reported_on < CURDATE() - INTERVAL 60 DAY;
        
        
	-- 3. Data Retrieval and Filtering Queries:
	-- Queries 1
	SELECT *
    FROM room_types
    WHERE rent BETWEEN 400 AND 800;
    
    -- Queries 2
    SELECT *
    FROM students
    WHERE fname LIKE 'A%';
    
    -- Queries 3
    SELECT * 
    FROM payments
    WHERE method IN ('FPX' ,'CARD');
    
    -- Queries 4
    SELECT *
    FROM rooms
    WHERE (floor_no=2 OR floor_no=3) AND NOT is_occupied;
	
    -- 4. Functions and Expressions
    -- Aggregate Function
	SELECT sum(amount) AS total_payments_collected
    FROM payments;
    
    -- String Function
    SELECT UPPER (CONCAT (fname, ' ', lname)) AS full_name
    FROM students;
    
-- Task 3 – Reporting and Aggregation (CLO2)
-- 1. Create view v_room_status
    CREATE VIEW v_room_status AS
	SELECT
		r.room_no,
		rt.type_name,
		rt.rent,
		r.floor_no,
		rt.capacity,

		(SELECT COUNT(s.student_id)			-- calculate n_occupants
		FROM students s
		WHERE s.room_id = r.room_id AND s.status = 'ACTIVE'
		) AS n_occupants,

		(SELECT COUNT(m.maint_id)			-- calculate pending_issues
		FROM maintenance m
		WHERE m.room_id = r.room_id AND m.status = 'OPEN'
		) AS pending_issues,
    
		((SELECT COUNT(s.student_id)		-- calculate is_vacant
		FROM students s
		WHERE s.room_id = r.room_id AND s.status = 'ACTIVE'
		) = 0
		) AS is_vacant

	FROM rooms r
	INNER JOIN room_types rt ON r.type_id = rt.type_id;
    
    SELECT * FROM v_room_status; -- show result
    
    -- 2. Summary Queries
    -- Total number of students per room type
    SELECT rt.type_name, COUNT(s.student_id) AS number_of_students
	FROM students s
    
	JOIN rooms r 
    ON s.room_id = r.room_id
    
	JOIN room_types rt 
    ON r.type_id = rt.type_id
    
	WHERE s.status = 'ACTIVE'
	GROUP BY rt.type_name;
    
    -- Average rent and total deposit per room type
    SELECT 
		type_name, 
        ROUND(AVG(rent), 2) AS average_rent, 
        ROUND(SUM(deposit),2) AS total_deposit
        
    FROM room_types
    GROUP BY type_name;
    
	-- Monthly payment totals grouped by year & month
    SELECT  year(paid_on) AS payment_year,
			month (paid_on) AS payment_month,
            sum(amount) AS total_monthly_payment
            
	FROM payments
    GROUP BY year(paid_on), month(paid_on)
    ORDER BY payment_year, payment_month;
    
	-- Count of OPEN maintenance issues per floor using HAVING COUNT
	SELECT 
		r.floor_no, 
        COUNT(m.maint_id) AS open_issues
        
    FROM maintenance m
    JOIN rooms r
    ON m.room_id = r.room_id
    WHERE m.status = 'OPEN'
    GROUP BY r.floor_no
    HAVING
		COUNT(m.maint_id) > 2;
    
    
    -- 3. Create final Report
    SELECT
		UPPER (CONCAT (s.fname,' ', s.lname)) AS 'Student Full Name',			-- Using UPPER() and CONCAT()
		s.email AS 'Student Email',
		r.room_no AS 'Room No',
		r.floor_no AS 'Floor',
		rt.type_name AS 'Room Type',
		ROUND(rt.rent, 0) AS 'Monthly Rent',			-- Using ROUND()
    
		CASE
			WHEN rt.rent < 600.00 THEN 'LOW'
			WHEN rt.rent < 1000.00 THEN 'MEDIUM'
			ELSE 'HIGH'
		END AS 'Rent Category',
    
		(SELECT COUNT(m.maint_id)						-- Using Count()
		 FROM maintenance m
		 WHERE m.room_id = r.room_id AND m.status = 'OPEN'
		) AS 'Pending Issues',
    
    s.checkin_date AS 'Check In Date',
    p.paid_on AS 'Rent Paid Date'

	FROM students s
    JOIN payments p ON  p.student_id = s.student_id 
	JOIN rooms r ON s.room_id = r.room_id
	JOIN room_types rt ON r.type_id = rt.type_id
	WHERE s.status = 'ACTIVE'
	ORDER BY s.fname ASC; 