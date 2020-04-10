package org.myroniuk.simplewebapp.utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import org.myroniuk.simplewebapp.beans.*;

public class DBUtils {
	
	public static UserAccount findUser(Connection connection, String userName,
			String password) throws SQLException {
		String sql = "SELECT a.USER_NAME, a.PASSWORD, a.GENDER "
				+ "FROM USER_ACCOUNT a WHERE a.USER_NAME = ? AND a.PASSWORD = ?";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, userName);
		statement.setString(2, password);
		ResultSet resultSet = statement.executeQuery();
		
		if (resultSet.next()) {
			String gender = resultSet.getString("GENDER");
			UserAccount user = new UserAccount();
			user.setUserName(userName);
			user.setPassword(password);
			user.setGender(gender);
			return user;
		}
		return null;
	}
	
	public static UserAccount findUser(Connection connection, String userName)
			throws SQLException {
		String sql = "SELECT a.USER_NAME, a.PASSWORD, a.GENDER "
				+ "FROM USER_ACCOUNT a WHERE a.USER_NAME = ?";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, userName);
		ResultSet resultSet = statement.executeQuery();
		
		if (resultSet.next()) {
			String password = resultSet.getString("PASSWORD");
			String gender = resultSet.getString("GENDER");
			UserAccount user = new UserAccount();
			user.setUserName(userName);
			user.setPassword(password);
			user.setGender(gender);
			return user;
		}
		return null;
	}
	
	public static List<Product> queryProduct(Connection connection)
			throws SQLException {
		String sql = "SELECT p.CODE, p.NAME, p.PRICE FROM PRODUCT p";
		PreparedStatement statement = connection.prepareStatement(sql);
		ResultSet resultSet = statement.executeQuery();
		
		List<Product> products = new ArrayList<Product>();
		while (resultSet.next()) {
			String code = resultSet.getString("CODE");
			String name = resultSet.getString("NAME");
			float price = resultSet.getFloat("PRICE");
			Product product = new Product(code, name, price);
			products.add(product);
		}
		return products;
	}
	
	public static Product findProduct(Connection connection, String code)
			throws SQLException {
		String sql = "SELECT p.CODE, p.NAME, p.PRICE FROM PRODUCT p WHERE p.CODE = ?";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, code);
		ResultSet resultSet = statement.executeQuery();
		
		if (resultSet.next()) {
			String name = resultSet.getString("NAME");
			float price = resultSet.getFloat("PRICE");
			Product product = new Product(code, name, price);
			return product;
		}
		return null;
	}
	
	public static void updateProduct(Connection connection, Product product)
			throws SQLException {
		String sql = "UPDATE PRODUCT SET NAME = ?, PRICE = ? WHERE CODE = ?";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, product.getName());
		statement.setFloat(2, product.getPrice());
		statement.setString(3, product.getCode());
		statement.executeUpdate();
	}
	
	public static void insertProduct(Connection connection, Product product)
			throws SQLException {
		String sql = "INSERT INTO PRODUCT(CODE, NAME, PRICE) VALUES(?, ?, ?)";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, product.getCode());
		statement.setString(2, product.getName());
		statement.setFloat(3, product.getPrice());
		statement.executeUpdate();
	}
	
	public static void deleteProduct(Connection connection, String code)
			throws SQLException {
		String sql = "DELETE FROM PRODUCT WHERE CODE = ?";
		PreparedStatement statement = connection.prepareStatement(sql);
		statement.setString(1, code);
		statement.executeUpdate();
	} 
}
