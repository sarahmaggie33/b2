//This file is part of Bertini 2.0.
//
// python/function_tree.hpp is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//This file is part of Bertini 2.0.
//
// python/bertini_python.hpp is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
// python/bertini_python.hpp is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with  python/bertini_python.hpp.  If not, see <http://www.gnu.org/licenses/>.
//
//  James Collins
//  West Texas A&M University
//  Spring 2016
//
//
//  python/operator_export.hpp:  Header file for exposing operator nodes to python.




#ifndef Xcode_b2_operator_visitors_hpp
#define Xcode_b2_operator_visitors_hpp

#include <bertini2/function_tree/operators/operator.hpp>
#include <bertini2/function_tree/operators/arithmetic.hpp>
#include <bertini2/function_tree/operators/trig.hpp>

#include "python_common.hpp"

namespace bertini{
	namespace python{
		
		using namespace boost::python;
		using namespace bertini::node;

		using Node = Node;
		using Nodeptr = std::shared_ptr<Node>;
		
		
		
		
		void ExportOperators();
		
		
		
		
		
		/**
		 UnaryOperator class(abstract)
		 */
		template<typename NodeBaseT>
		class UnaryOpVisitor: public def_visitor<UnaryOpVisitor<NodeBaseT> >
		{
		public:
			template<class PyClass>
			void visit(PyClass& cl) const;
		};

	
		
		
		/** NaryOperator class(abstract)
		 */
		template<typename NodeBaseT>
		class NaryOpVisitor: public def_visitor<NaryOpVisitor<NodeBaseT> >
		{
		public:
			template<class PyClass>
			void visit(PyClass& cl) const;
		};

		
		
		
		
		/**
		 SumOperator and MultOperator classes
		 */
		template<typename NodeBaseT>
		class SumMultOpVisitor: public def_visitor<SumMultOpVisitor<NodeBaseT> >
		{
			friend class def_visitor_access;
			
		public:
			template<class PyClass>
			void visit(PyClass& cl) const;
			
			
			
			
		private:
			void (NodeBaseT::*addChild2)(std::shared_ptr<Node> child, bool) = &NodeBaseT::AddChild;

		};

		
		
		
		/**
		 PowerOperator class
		 */
		template<typename NodeBaseT>
		class PowerOpVisitor: public def_visitor<PowerOpVisitor<NodeBaseT> >
		{
			friend class def_visitor_access;
			
		public:
			template<class PyClass>
			void visit(PyClass& cl) const;
			
		};

		
		/**
		 IntegerPowerOperator class 
		 */
		template<typename NodeBaseT>
		class IntPowOpVisitor: public def_visitor<IntPowOpVisitor<NodeBaseT> >
		{
			friend class def_visitor_access;
			
		public:
			template<class PyClass>
			void visit(PyClass& cl) const;
			
		private:
			std::string (NodeBaseT::*getexp)() const = &NodeBaseT::exponent;
			void (NodeBaseT::*setexp)(const std::string &) = &NodeBaseT::set_exponent;
			
		};

		
		
	} //re: namespace python
}//re: namespace bertini

		
		
		
		
		
		
		
		
		
		
#endif
