USE bike_store;
--SQL

--1
SELECT * FROM dbo.staffs WHERE staff_id=2;

--2
SELECT COUNT(*) FROM dbo.staffs

--3
SELECT * FROM dbo.customers WHERE city='Monsey'

--4
SELECT first_name+' '+last_name FROM dbo.customers WHERE phone IS NOT null

--5
SELECT brand_id,COUNT(product_id) FROM dbo.products
GROUP BY brand_id

--6

SELECT product_name FROM dbo.products
WHERE model_year =2019 AND list_price>1000

--7
SELECT order_id FROM dbo.orders
WHERE order_status =2

--8
SELECT store_id,SUM(quantity) AS total FROM dbo.stocks
GROUP BY store_id

--9
SELECT order_id,product_id,quantity,list_price,discount,list_price * quantity AS amount FROM dbo.order_items

--10
SELECT order_id,SUM(list_price*quantity) FROM dbo.order_items
GROUP BY order_id

--11
SELECT category_id FROM dbo.products
GROUP BY category_id
HAVING COUNT(product_id)>50

--12
SELECT * FROM dbo.orders WHERE year(order_date)=2018 AND MONTH(order_date)=1

--13
SELECT staff_id FROM dbo.orders WHERE order_date='2018-4-15'

--14
SELECT order_id FROM dbo.orders WHERE shipped_date-order_date=1

--15
SELECT customer_id FROM dbo.orders
WHERE YEAR(order_date) = 2018
GROUP BY customer_id
having COUNT(*)>2

--câu 16
SELECT product_id,product_name FROM dbo.products WHERE model_year = 2018

--câu 17
SELECT product_name FROM dbo.brands 
JOIN dbo.products ON products.brand_id = brands.brand_id
JOIN dbo.categories ON categories.category_id = products.category_id
WHERE category_name='Mountain Bikes' AND brand_name='Trek'

--câu 18
SELECT TOP 1  product_id, COUNT(*) AS order_number FROM dbo.order_items GROUP BY product_id ORDER BY order_number DESC

--câu 19
SELECT customer_id FROM dbo.orders
GROUP BY customer_id
HAVING MAX(YEAR(order_date))<2017

--câu 20
SELECT products.product_id,product_name,brand_name FROM dbo.products
JOIN dbo.brands ON brands.brand_id = products.brand_id
JOIN dbo.stocks ON stocks.product_id = products.product_id
WHERE quantity =0

--câu 21
SELECT order_id FROM dbo.orders JOIN dbo.stores ON stores.store_id = orders.store_id JOIN dbo.customers ON customers.customer_id = orders.customer_id
WHERE customers.city = stores.city AND order_status = 1

--câu 22
SELECT TOP 1 orders.customer_id,first_name,last_name,order_date 
FROM dbo.orders 
JOIN dbo.customers ON customers.customer_id = orders.customer_id 
WHERE YEAR(order_date) = 2017 
ORDER BY order_date ASC;

--câu 23
SELECT top 1 * ,DATEDIFF(DAY,order_date,shipped_date) AS delivery_date FROM dbo.orders ORDER BY delivery_date DESC; 

--câu 25
UPDATE dbo.orders SET shipped_date = DATEADD(DAY,1,shipped_date) WHERE order_date = '2018-4-1' AND shipped_date IS NULL;

--câu 27
ALTER TABLE dbo.orders ADD CHECK (order_date<=shipped_date)

--câu 28 
ALTER TABLE dbo.products ADD CHECK (list_price>0)

--câu 29
ALTER TABLE	dbo.stores ADD UNIQUE(store_name)


--T-SQL
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
CREATE FUNCTION stock_by_productid(@productid int)
RETURNS int
AS
BEGIN
	DECLARE @storeid INT;
	SELECT 
END

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
CREATE FUNCTION order_got_10_percent_discount(@dis)
RETURNS @order TABLE(order_id int)
AS
BEGIN
	INSERT INTO @order(order_id)
	SELECT order_id FROM dbo.order_items WHERE discount>0.1
	RETURN;
END

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
CREATE FUNCTION sum_product (@order_id int)
RETURNS int 
AS
BEGIN
	DECLARE @sumq INT;
	SELECT @sumq = SUM(quantity) FROM dbo.order_items WHERE order_id = @order_id;
	RETURN @sumq;
END

--câu 14
alter FUNCTION sum_product_by_id_storeid (@product_id int, @store_id int)
RETURNS int 
AS
BEGIN
	DECLARE @sumproduct int;
	SELECT @sumproduct = SUM(quantity) FROM dbo.order_items JOIN dbo.orders ON orders.order_id = order_items.order_id WHERE product_id = @product_id AND store_id = @store_id;
	return @sumproduct;
END

SELECT * FROM sum_product_by_id_storeid(20,1)

--câu 16
alter function order_date_check (@shipped date)
RETURNS @order TABLE (order_id int,street varchar(255))
AS
BEGIN
	INSERT INTO @order(order_id,street)
	SELECT order_id,street FROM dbo.orders JOIN dbo.customers ON customers.customer_id = orders.customer_id WHERE shipped_date = @shipped
	RETURN;
END

SELECT * from order_date_check('2016-01-03')


--Câu 17
CREATE TRIGGER prevent_delete_orders
ON orders
FOR DELETE 
AS 
BEGIN
	ROLLBACK TRAN
END

--Câu 18
alter TRIGGER update_products
ON products
FOR UPDATE, INSERT
AS 

BEGIN
	IF EXISTS (SELECT 1 FROM inserted )
	BEGIN
		IF(SELECT COUNT(*) FROM inserted WHERE model_year > YEAR(GETDATE()))>0
		BEGIN
			ROLLBACK TRAN;
		END
	END
END

--câu 19
CREATE TRIGGER update_orderitems
ON order_items
FOR UPDATE,INSERT 
AS 
BEGIN
	IF EXISTS (SELECT 1 FROM inserted)
	BEGIN
		IF(SELECT COUNT(*) FROM dbo.order_items join dbo.stocks ON stocks.product_id = order_items.product_id WHERE dbo.order_items.quantity > dbo.stocks.quantity )>0
		BEGIN
			ROLLBACK TRAN
		END
	END
END

