#ifndef TOOL_HPP
#define TOOL_HPP

class Tool
{
	public:
		Tool(): _owner(NULL) { VERBOSE };
		~Tool() { VERBOSE };
	
		virtual void use() = 0;

		void giveTool(Worker *owner)
		{ VERBOSE
			if (this->_owner != NULL)
				this->_owner->removeTool(this);
			this->_owner = owner;
			this->_owner->addTool(this);
		};

		void returnTool()
		{ VERBOSE
			this->_owner->removeTool(this);
			_owner = NULL;
		};

	protected:
		Worker	*_owner;
};

#endif
