CREATE TABLE Items (
id NUMBER,
name VARCHAR2(30),
description VARCHAR2(200),
category VARCHAR2(30),
price NUMBER
);

CREATE TABLE MeasureUnits (
id NUMBER,
name VARCHAR2(30),
description VARCHAR2(10)
);

CREATE TABLE ItemCategories (
id NUMBER,
name VARCHAR2(30),
parentId NUMBER
);

CREATE TABLE orderStatus (
id NUMBER,
name VARCHAR2(30)
);