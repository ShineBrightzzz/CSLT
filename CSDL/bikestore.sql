USE bike_store;

--T-SQL
-- câu 1
CREATE FUNCTION order_each_day(@Ngay date)
RETURNS int
AS
BEGIN
	DECLARE @orders INT;
	SELECT @orders = COUNT(*) FROM dbo.orders WHERE order_date = @Ngay;
	RETURN @orders;
END



--câu 2
create FUNCTION staff_stores(@store_id int)
RETURNS @staff TABLE
(
    staff_id int -- Adjust the data types as needed
    -- Add more columns as needed
)
AS 
BEGIN
    INSERT INTO @staff (staff_id) -- Insert the columns you want to return
    SELECT staff_id
    FROM dbo.staffs
    WHERE store_id = @store_id;

    RETURN;
END;

SELECT * FROM staff_stores(3);


--câu 3
ALTER FUNCTION order_by_customer(@customer_id int)
RETURNS @order TABLE (order_id int,customer_id int,order_status int, order_date date, required_date date, shipped_date date, store_id int, staff_id int)
AS
BEGIN
	INSERT INTO @order(order_id ,customer_id ,order_status , order_date , required_date , shipped_date , store_id , staff_id )
	SELECT order_id ,customer_id ,order_status , order_date , required_date , shipped_date , store_id , staff_id FROM dbo.orders WHERE customer_id = @customer_id;
	RETURN;
END

SELECT * FROM order_by_customer(1212)

--câu 4
CREATE FUNCTION staff_by_lastname(@lastname varchar(50))
RETURNS @staff_info TABLE(staff_id int,first_name varchar(50),last_name varchar(50),email varchar(255),phone varchar(25),ACTIVE tinyint, store_id int,manager_id int)
AS 
BEGIN
	INSERT INTO @staff_info(staff_id ,first_name ,last_name ,email ,phone ,ACTIVE , store_id ,manager_id )
	SELECT staff_id ,first_name ,last_name ,email ,phone ,ACTIVE , store_id ,manager_id FROM staffs WHERE last_name = @lastname;
	RETURN;
END

SELECT * FROM staff_by_lastname('David')

--câu 5
CREATE FUNCTION profit_month(@month month)


--câu 6
CREATE sum_order(@order int)
RETURNS int
AS 
BEGIN
	
END

--câu 7
CREATE FUNCTION order_by_store_and_date(@store_id int, @order_date date)
RETURNS @orders TABLE(order_id INT,
	customer_id INT,
	order_status tinyint ,
	order_date DATE ,
	required_date DATE ,
	shipped_date DATE,
	store_id INT ,
	staff_id INT )
AS BEGIN 
	INSERT INTO @orders(order_id,customer_id, order_status ,order_date,required_date,shipped_date,store_id,staff_id)
	SELECT order_id,customer_id, order_status ,order_date,required_date,shipped_date,store_id,staff_id FROM orders WHERE store_id = @store_id AND order_date = @order_date
	RETURN;
END

SELECT * FROM order_by_store_and_date(1,'2016-01-01')

--câu 8

--câu 9
CREATE FUNCTION order_by_price(@price int)
RETURNS @product TABLE (product_id int, product_name varchar(255), list_price decimal(10,2))
AS 
BEGIN
	INSERT INTO @product(product_id , product_name , list_price )
	SELECT product_id , product_name , list_price  FROM products WHERE list_price<@price; 
	return
END

SELECT * FROM order_by_price(400)

--câu 10

--câu 11
CREATE FUNCTION last_time_product_sold(@product_id int)
RETURNs date 
AS 
BEGIN
	DECLARE @date DATE;

	SELECT @date = MAX(order_date)  FROM orders JOIN order_items ON orders.order_id = order_items.order_id WHERE product_id = @product_id
	RETURN @date;
END

select dbo.last_time_product_sold(20);

--câu 12
CREATE function customer_bought (@customer_id int,@year int)
RETURNS tinyint
AS 
BEGIN
	IF EXISTS(SELECT 1 FROM orders WHERE customer_id = @customer_id AND YEAR(order_date) = @year)
		RETURN 1; 

	RETURN 0;
	
END

SELECT dbo.customer_bought(259,2017)

--câu 13
CREATE sum_product (@order_id int)
RETURNS int 
AS
BEGIN
	
END

SELECT * FROM 