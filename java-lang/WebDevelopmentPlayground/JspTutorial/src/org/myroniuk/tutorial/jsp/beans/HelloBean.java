package org.myroniuk.tutorial.jsp.beans;

public class HelloBean {
	
	private String name;
	
	// Class is required default constructor
	public HelloBean() {
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getHello() {
		if (this.name == null) {
			return "Hello every body";
		}
		return "Hello " + this.name;
	}
}
